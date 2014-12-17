#include <windows.h>
#include "utils.h"
#include "fusemain.h"
#include "ScopeGuard.h"
#include "docanfuse.h"

#ifdef __CYGWIN__
#define FWPRINTF dummy_fwprintf
int dummy_fwprintf(FILE*, const wchar_t*, ...)
{
	return 0;
}
#else
#define FWPRINTF fwprintf
#endif

static impl_fuse_context * the_impl=NULL;

extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	return TRUE;
}

static int DOKAN_CALLBACK FuseFindFiles(
				LPCWSTR				FileName,
				PFillFindData		FillFindData, // function pointer
				PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"FindFiles :%s\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->find_files(FileName,FillFindData,
		DokanFileInfo));
}

static int DOKAN_CALLBACK FuseOpenDirectory(
				LPCWSTR					FileName,
				PDOKAN_FILE_INFO		DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"OpenDirectory : %s\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->open_directory(FileName,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseCleanup(
					LPCWSTR					FileName,
					PDOKAN_FILE_INFO		DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"Cleanup: %s\n\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->cleanup(FileName,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseCreateDirectory(
					LPCWSTR					FileName,
					PDOKAN_FILE_INFO		DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"CreateDirectory : %s\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->create_directory(FileName,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseDeleteDirectory(
					LPCWSTR				FileName,
					PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"DeleteDirectory %s\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->delete_directory(FileName,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseCreateFile(
				 LPCWSTR				FileName,
				 DWORD					AccessMode,
				 DWORD					ShareMode,
				 DWORD					CreationDisposition,
				 DWORD					FlagsAndAttributes,
				 PDOKAN_FILE_INFO		DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	AccessMode|=GENERIC_READ;
	if (impl->debug()) FWPRINTF(stderr, L"CreateFile : %s AccessMode: %x (%c%c)\n", FileName,
										AccessMode,
										(AccessMode & GENERIC_READ) != 0 ? 'r' :' ',
										(AccessMode & GENERIC_WRITE) != 0 ? 'w' :' ');
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->create_file(FileName,AccessMode,ShareMode,
		CreationDisposition,FlagsAndAttributes,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseCloseFile(
				LPCWSTR					FileName,
				PDOKAN_FILE_INFO		DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"Close: %s\n\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->close_file(FileName,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseReadFile(
			   LPCWSTR				FileName,
			   LPVOID				Buffer,
			   DWORD				BufferLength,
			   LPDWORD				ReadLength,
			   LONGLONG				Offset,
			   PDOKAN_FILE_INFO		DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
//	if (impl->debug()) FWPRINTF(stderr, L"ReadFile : %s\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->read_file(FileName,Buffer,
		BufferLength,ReadLength,Offset,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseWriteFile(
				LPCWSTR		FileName,
				LPCVOID		Buffer,
				DWORD		NumberOfBytesToWrite,
				LPDWORD		NumberOfBytesWritten,
				LONGLONG			Offset,
				PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"WriteFile : %s, offset %I64d, length %d\n", 
		FileName, Offset, NumberOfBytesToWrite);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->write_file(FileName,Buffer,
		NumberOfBytesToWrite,NumberOfBytesWritten,Offset,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseFlushFileBuffers(
				LPCWSTR				FileName,
				PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"FlushFileBuffers : %s\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->flush_file_buffers(FileName,
		DokanFileInfo));
}

static int DOKAN_CALLBACK FuseGetFileInformation(
				LPCWSTR							FileName,
				LPBY_HANDLE_FILE_INFORMATION	HandleFileInformation,
				PDOKAN_FILE_INFO				DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"GetFileInfo : %s\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->get_file_information(FileName,
		HandleFileInformation,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseDeleteFile(
				 LPCWSTR				FileName,
				 PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"DeleteFile %s\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->delete_file(FileName,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseMoveFile(
				LPCWSTR				FileName, // existing file name
				LPCWSTR				NewFileName,
				BOOL				ReplaceIfExisting,
				PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"MoveFile %s -> %s\n\n", FileName, NewFileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->move_file(FileName,NewFileName,
		ReplaceIfExisting,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseLockFile(
				LPCWSTR				FileName,
				LONGLONG			ByteOffset,
				LONGLONG			Length,
				PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"LockFile %s\n", FileName);

	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->lock_file(FileName,ByteOffset,
		Length,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseUnlockFile(
				LPCWSTR				FileName,
				LONGLONG			ByteOffset,
				LONGLONG			Length,
				PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"UnlockFile %s\n", FileName);

	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->unlock_file(FileName,ByteOffset,
		Length,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseSetEndOfFile(
				LPCWSTR				FileName,
				LONGLONG			ByteOffset,
				PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"SetEndOfFile %s, %I64d\n", FileName, ByteOffset);

	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->set_end_of_file(FileName,
		ByteOffset,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseSetFileAttributes(
				LPCWSTR				FileName,
				DWORD				FileAttributes,
				PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"SetFileAttributes %s\n", FileName);

	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->set_file_attributes(FileName,
		FileAttributes,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseSetFileTime(
				LPCWSTR				FileName,
				CONST FILETIME*		CreationTime,
				CONST FILETIME*		LastAccessTime,
				CONST FILETIME*		LastWriteTime,
				PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"SetFileTime %s\n", FileName);
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->set_file_time(FileName,
		CreationTime,LastAccessTime,LastWriteTime,DokanFileInfo));
}

static int DOKAN_CALLBACK FuseGetDiskFreeSpace(PULONGLONG FreeBytesAvailable,
				PULONGLONG TotalNumberOfBytes, PULONGLONG TotalNumberOfFreeBytes,
				PDOKAN_FILE_INFO DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"GetDiskFreeSpace\n");
	
	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->get_disk_free_space(FreeBytesAvailable,TotalNumberOfBytes,
		TotalNumberOfFreeBytes, DokanFileInfo));
}

static int DOKAN_CALLBACK GetVolumeInformation(
		LPWSTR VolumeNameBuffer,
		DWORD VolumeNameSize,
		LPDWORD VolumeSerialNumber,
		LPDWORD MaximumComponentLength,
		LPDWORD FileSystemFlags,
		LPWSTR FileSystemNameBuffer,
		DWORD FileSystemNameSize,
		PDOKAN_FILE_INFO DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"Unmount\n");

	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->get_volume_information(VolumeNameBuffer,VolumeNameSize,
		FileSystemNameBuffer,FileSystemNameSize, DokanFileInfo));
}

static int DOKAN_CALLBACK FuseUnmount(PDOKAN_FILE_INFO	DokanFileInfo)
{
	impl_fuse_context *impl=the_impl;
	if (impl->debug()) FWPRINTF(stderr, L"Unmount\n");

	impl_chain_guard guard(impl,DokanFileInfo->ProcessId);
	return -errno_to_win32_error(impl->unmount(DokanFileInfo));
}

int fuse_interrupted(void)
{
	return 0; //TODO: fix this
}

static DOKAN_OPERATIONS dokanOperations = {
	FuseCreateFile,
	FuseOpenDirectory,
	FuseCreateDirectory,
	FuseCleanup,
	FuseCloseFile,
	FuseReadFile,
	FuseWriteFile,
	FuseFlushFileBuffers,
	FuseGetFileInformation,
	FuseFindFiles,
	NULL, //FindFilesWithPattern
	FuseSetFileAttributes,
	FuseSetFileTime,
	FuseDeleteFile,
	FuseDeleteDirectory,
	FuseMoveFile,
	FuseSetEndOfFile,
	FuseLockFile,
	FuseUnlockFile,
	FuseGetDiskFreeSpace,
	GetVolumeInformation, 
	FuseUnmount // Unmount
};

int do_fuse_loop(struct fuse *fs, bool mt)
{
	if (!fs->ch.get() || fs->ch->mountpoint.empty())
		return -1;

	//Calculate umasks
	int umask=fs->conf.umask;
	if (umask==0) umask=0777; //It's OCTAL! Really!
	int dirumask=fs->conf.dirumask;
	if (dirumask==0) dirumask=umask;
	int fileumask=fs->conf.fileumask;
	if (fileumask==0) fileumask=umask;

	impl_fuse_context impl(&fs->ops,fs->user_data, fs->conf.debug!=0, 
		fileumask, dirumask, fs->conf.fsname, fs->conf.volname);
	the_impl=&impl;

	//Parse Dokan options
	PDOKAN_OPTIONS dokanOptions = (PDOKAN_OPTIONS)malloc(sizeof(DOKAN_OPTIONS));
	ZeroMemory(dokanOptions, sizeof(DOKAN_OPTIONS));
	dokanOptions->UseKeepAlive=1;

	wchar_t mount[MAX_PATH+1];
	mbstowcs(mount,fs->ch->mountpoint.c_str(),MAX_PATH);

	dokanOptions->DriveLetter = mount[0];	
	//wcsncpy(dokanOptions->MountPath,mount, MAX_PATH);
	dokanOptions->ThreadCount = mt?FUSE_THREAD_COUNT:1;
	
	//Debug
	dokanOptions->DebugMode = fs->conf.debug;
	dokanOptions->UseStdErr= fs->conf.debug;	

	//Load Dokan DLL
	if (!fs->ch->init())
		return -1; //Couldn't load DLL. TODO: UGLY!!

	//The main loop!
	fs->within_loop=true;
	int res=fs->ch->ResolvedDokanMain(dokanOptions, &dokanOperations);
	fs->within_loop=false;
	return res;
}

bool fuse_chan::init()
{
	dokanDll=LoadLibraryW(DOKAN_DLL);
	if (!dokanDll) return false;

	ResolvedDokanMain=(DokanMainType)GetProcAddress(dokanDll,"DokanMain");
	ResolvedDokanUnmount=(DokanUnmountType)GetProcAddress(dokanDll,"DokanUnmount");

	if (!ResolvedDokanMain || !ResolvedDokanUnmount) return false;
	return true;
}

fuse_chan::~fuse_chan()
{
	if (dokanDll)
		FreeLibrary(dokanDll);
}

///////////////////////////////////////////////////////////////////////////////////////
////// This are just "emulators" of native FUSE api for the sake of compatibility
///////////////////////////////////////////////////////////////////////////////////////
#define FUSE_LIB_OPT(t, p, v) { t, offsetof(struct fuse_config, p), v }

enum { KEY_HELP };

static const struct fuse_opt fuse_lib_opts[] = {
    FUSE_OPT_KEY("-h",                    KEY_HELP),
    FUSE_OPT_KEY("--help",                KEY_HELP),
    FUSE_OPT_KEY("debug",                 FUSE_OPT_KEY_KEEP),
    FUSE_OPT_KEY("-d",                    FUSE_OPT_KEY_KEEP),
    FUSE_LIB_OPT("debug",                 debug, 1),
    FUSE_LIB_OPT("-d",                    debug, 1),
    FUSE_LIB_OPT("umask=%o",              umask, 0),
	FUSE_LIB_OPT("fileumask=%o",          fileumask, 0),
	FUSE_LIB_OPT("dirumask=%o",           dirumask, 0),
	FUSE_LIB_OPT("fsname=%s",			  fsname, 0),
	FUSE_LIB_OPT("volname=%s",			  volname, 0),
	FUSE_LIB_OPT("setsignals=%s",	      setsignals, 0),
    FUSE_OPT_END
};

static void fuse_lib_help(void)
{
    fprintf(stderr,
"    -o umask=M             set file and directory permissions (octal)\n"
"    -o fileumask=M         set file permissions (octal)\n"
"    -o dirumask=M          set directory permissions (octal)\n"
"    -o fsname=M            set filesystem name\n"
"    -o volname=M           set volume name\n"
"    -o setsignals=M        set signal usage (1 to use)\n"
"\n");
}

static int fuse_lib_opt_proc(void *data, const char *arg, int key,
                             struct fuse_args *outargs)
{
    (void) arg; (void) outargs;

    if (key == KEY_HELP) {
        struct fuse_config *conf = (struct fuse_config *) data;
        fuse_lib_help();
        conf->help = 1;
    }

    return 1;
}

int fuse_is_lib_option(const char *opt)
{
	return fuse_opt_match(fuse_lib_opts, opt);
}

int fuse_loop_mt(struct fuse *f)
{
	return do_fuse_loop(f,true);
}

int fuse_loop(struct fuse *f)
{
	return do_fuse_loop(f,false);
}

struct fuse_chan *fuse_mount(const char *mountpoint, struct fuse_args *args)
{
	if (mountpoint==NULL || strlen(mountpoint)==0) return NULL;

	std::auto_ptr<fuse_chan> chan(new fuse_chan());
	//NOTE: we used to do chan->init() here to check that Dokan DLLs can be loaded.
	//However, this does not live well with Cygwin. It's common for filesystem drivers
	//to daemon()ize themselves (which involves fork() call) and forking doesn't work
	//with Dokan. So defer loading until the main loop.
	
	chan->mountpoint=mountpoint;
	return chan.release();
}

void fuse_unmount(const char *mountpoint, struct fuse_chan *ch)
{
	if (ch==NULL || mountpoint==NULL || strlen(mountpoint)==0) return;
	//Unmount attached FUSE filesystem
	ch->ResolvedDokanUnmount(mountpoint[0]); //Ugly :(
}

//Used from fuse_helpers.c
extern "C" int fuse_session_exit(struct fuse_session *se)
{
	fuse_unmount(se->ch->mountpoint.c_str(),se->ch);
	return 0;
}

struct fuse *fuse_new(struct fuse_chan *ch, struct fuse_args *args,
	const struct fuse_operations *op, size_t op_size,
	void *user_data)
{
	std::auto_ptr<fuse> res(new fuse());
	res->sess.ch=ch;
	res->ch.reset(ch); //Attach channel
	res->user_data=user_data;

	//prepare 'safe' options
	fuse_operations safe_ops={0};
	memcpy(&safe_ops,op,op_size>sizeof(safe_ops)?sizeof(safe_ops):op_size);
	res->ops=safe_ops;

	//Get debug param and filesystem name
	if (fuse_opt_parse(args, &res->conf, fuse_lib_opts, fuse_lib_opt_proc) == -1)
		return NULL;
	//res->conf.debug=1;

	return res.release();
}

void fuse_exit(struct fuse *f)
{
	//A hack - unmount the attached filesystem, it will cause the loop to end
	if (f==NULL || !f->ch.get() || f->ch->mountpoint.empty()) return;
	//Unmount attached FUSE filesystem
	f->ch->ResolvedDokanUnmount(f->ch->mountpoint.at(0)); //Ugly :(
}

void fuse_destroy(struct fuse *f)
{
	delete f;
}

struct fuse *fuse_setup(int argc, char *argv[],
		const struct fuse_operations *op, size_t op_size,
		char **mountpoint, int *multithreaded, void *user_data)
{
	struct fuse_args args = FUSE_ARGS_INIT(argc, argv);
	struct fuse_chan *ch=NULL;
	struct fuse *fuse;
	int foreground;
	int res;

	res = fuse_parse_cmdline(&args, mountpoint, multithreaded, &foreground);
	if (res == -1)
		return NULL;

	ch = fuse_mount(*mountpoint, &args);

	fuse = fuse_new(ch, &args, op, op_size, user_data);
	fuse_opt_free_args(&args);
	if (fuse == NULL || ch==NULL)
		goto err_unmount;

	res = fuse_daemonize(foreground);
	if (res == -1)
		goto err_unmount;

	if (fuse->conf.setsignals)
	{
		res = fuse_set_signal_handlers(fuse_get_session(fuse));
		if (res == -1)
			goto err_unmount;
	}

	return fuse;

err_unmount:
	fuse_unmount(*mountpoint, ch);
	if (fuse)
		fuse_destroy(fuse);
	free(*mountpoint);
	return NULL;
}

void fuse_teardown(struct fuse *fuse, char *mountpoint)
{
	struct fuse_session *se = fuse_get_session(fuse);
	struct fuse_chan *ch = se->ch;	
	if (fuse->conf.setsignals)
		fuse_remove_signal_handlers(se);
	fuse_unmount(mountpoint, ch);
	fuse_destroy(fuse);
	free(mountpoint);
}

int fuse_exited(struct fuse *f)
{
	return !f->within_loop;
}

struct fuse_session *fuse_get_session(struct fuse *f)
{
	return &f->sess;
}

int fuse_main_real(int argc, char *argv[], const struct fuse_operations *op,
					size_t op_size, void *user_data)
{
	struct fuse *fuse;
	char *mountpoint;
	int multithreaded;
	int res;

	fuse = fuse_setup(argc, argv, op, op_size, &mountpoint,
		&multithreaded, user_data);
	if (fuse == NULL)
		return 1;

	//MT loops are only supported on MSVC
#ifdef _MSC_VER
	if (multithreaded)
		res = fuse_loop_mt(fuse);
	else
		res = fuse_loop(fuse);
#else
		res = fuse_loop(fuse);
#endif		

	fuse_teardown(fuse, mountpoint);
	if (res == -1)
		return 1;
	
	return 0;
}
