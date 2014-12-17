/*
 * i18n.c: Internationalization
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id: i18n.c,v 1.4 2005/01/01 22:11:13 Exp $
 *
 */

#include "i18n.h"

const tI18nPhrase tlPhrases[] = {
    {"Online Update",           // English
     "Softwareupdate - Online", // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "St�hnout nov� moduly",	// Czech
     },
    {"Install",                 // English
     "Ausf�hren",               // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Instalovat",				// Czech
     },
    {"Select",                  // English
     "Ausw�hlen",               // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "V�b�r",					// Czech
     },
    {"Add",                     // English
     "Hinzuf�gen",              // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "P�idat",					// Czech
     },
     {"Insert",                 // English
     "Einf�gen",              	// Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Vlo�it",					// Czech
     },
     {"Undo",                   // English
     "R�ckg�ngig",              // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Zru�it",					// Czech
     },
     {"Save",                   // English
     "Speichern",              	// Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Ulo�it",					// Czech
     },
     {"Error",                  // English
     "Fehler",              	// Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Chyba",					// Czech
     },
     {"Unable to read from sources.list!",            // English
     "Konnte sources.list nicht lesen!",              // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Nen� mo�n� ��st ze sources.list ",		// Czech
     },
     {"Unable to write to surces.list!",                  // English
     "Konnte sources.list nicht �berschreiben!",          // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Nen� mo�n� zapsat do sources.list",		// Czech
     },
     {"Update",                  // English
     "Einlesen",                // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "St�hnout nov� data",		// Czech
     },
    {"Upgrade",                 // English
     "Aktualisieren",           // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Aktualizovat",			// Czech
     },
    {"\t   Name\t  Info",       // English
     "\t   Paket\t  Beschreibung",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "\t   Jm�no\t   Info",		// Czech
     },
    {"\n Name: %s\n Version: %s\n\n Info: %s",  // English
     "\n Paket: %s\n Version: %s\n\n Beschreibung: %s", // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "\n Jm�no: %s\n Verze: %s\n Info: %s",		// Czech
     },
    {"Dpkg: starting update",             // English
     "Aktualisierung gestartet.",       // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: St�hnout nov� data",		// Czech
     },
    {"Dpkg: upgrade complete",          // English
     "Upgrade ausgef�hrt.",     // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: Aktualizace komletn�",		// Czech
     },
    {"Dpkg: update complete",   // English
     "Update ausgef�hrt.",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: Update kompletn�",	// Czech
     },
    {"Copy",                    // English
     "Kopieren",                // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Kop�rovat",				// Czech
     },
    {"Dpkg: starting upgrade",            // English
     "Aktualisierung gestartet",        // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: spustit akzualizaci",		// Czech
     },
    {"Dpkg: removing Packages",         // English
     "Paket l�schen",           // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: odstran�n� modul�",			// Czech
     },
    {"Dpkg: starting installation",     // English
     "Paket installieren",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: start instalace",	// Czech
     },
    {"Dpkg: installation complete",               // English
     "Installation ausgef�hrt.", // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: instalace je kompletn�",		// Czech
     },
    {"Dpkg: Packages removed",               // English
     "Entfernen ausgef�hrt.",   // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: moduly jsou odstran�ny",		// Czech
     },
    {"Dpkg: installation error",               // English
     "Installation fehlgeschlagen.", // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: chyba v instalaci",			// Czech
     },
    {"Dpkg: Package remove error",      // English
     "Entfernen fehlgeschlagen.", // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: chyba v odstran�n� modulu",			// Czech
     },
    {"Dpkg: error updating package list",               // English
     "Update der Paketliste fehlgeschlagen!", // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Dpkg: chyba p�i stahov�n� seznamu modul�",
     },
    {"Server",					// English
     "Server",					// Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     ""                         // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Server",					// Czech
     },
     {"Updating sources...",          // English
      "Aktualisiere Quellen...",      // Deutsch
      "",                        // Slovenski
      "",                        // Italiano
      "",                        // Nederlands
      "",                        // Portugu�s
      "",                        // Fran�ais
      "",                        // Norsk
      "",                        // suomi
      "",                        // Polski
      "",                        // Espa�ol
      "",                        // ��������
      "",                        // Svenska
      "",                        // Romaneste
      "",                        // Magyar
      "",                        // Catal�
      "",                        // ������� (Russian)
      "",                        // Hrvatski (Croatian)
      "",                        // Eesti
      "",                        // Dansk
      "Aktualizace",			 // Czech
     },
     {"Updating packages...",                    // English
      "Aktualisiere Pakete...",      // Deutsch
      "",                        // Slovenski
      "",                        // Italiano
      "",                        // Nederlands
      "",                        // Portugu�s
      "",                        // Fran�ais
      "",                        // Norsk
      "",                        // suomi
      "",                        // Polski
      "",                        // Espa�ol
      "",                        // ��������
      "",                        // Svenska
      "",                        // Romaneste
      "",                        // Magyar
      "",                        // Catal�
      "",                        // ������� (Russian)
      "",                        // Hrvatski (Croatian)
      "",                        // Eesti
      "",                        // Dansk
      "Aktualizace paket�",		 // Czech
     },
    {"Now select updgrade to install the new packages.",                    // English
     "W�hlen Sie aktualisieren um die neuen Pakete zu installieren.",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Nyn� vyberte moduly pro aktualizaci",			// Czech
     },
    {"No updates found. The software is up to date.",              // English
     "Ihre ReelBox ist bereits auf aktuellem Softwarestand.",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "��dn� aktualizace nenalezeny. Software je aktu�ln�",		// Czech
     },
    {"Sources up to date. Searching for updates...",           // English
     "Quellen aktualisiert. Suche nach neuen Paketen...",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Zdroje aktualizov�ny. Hled�n� nov�ch paket�",			// Czech
     },
    {"Sources up to date. Searching for packages...",                    // English
     "Quellen aktualisiert. Suche nach Paketen...",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Zdroje aktualizov�ny. Hled�n� nov�ch paket�",			// Czech
     },
    {"Failed to process all packages!",                    // English
     "Konnte nicht alle Pakete bearbeiten!",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Zru�eno stahov�n� v�ech modul�!",			// Czech
     },
    {"Failed to update all sources! Searching for updates...",                    // English
     "Konnte nicht alle Quellen aktualisieren! Suche nach neuen Paketen...",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Zru�ena aktualizace v�ech zdroj�! Prohled�v�n� modul�..",		// Czech
     },
    {"Failed to update all sources! Searching for packages...",                    // English
     "Konnte nicht alle Quellen aktualisieren! Suche nach Paketen...",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Zru�ena aktualizace v�ech zdroj�! Prohled�v�n� modul�..",
     },

    {"All changes successfull!",          // English
     "Alle �nderungen erfolgreich!",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "V�echny zm�ny �sp�n� dokon�eny",			// Czech
     },
     {"Failed to process all packages!",                    // English
     "Konnte nicht alle Pakete bearbeiten!",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Zru�eno stahov�n� v�ech modul�!",			// Czech
     },
    {"Downloading Packages...",                    // English
     "Lade Pakete...",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Stahov�n� modul�..",		// Czech
     },
    {"Processing Packages...",                    // English
     "Bearbeite Pakete...",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "",
     },
     {"Packages",                    // English
     "Pakete",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Moduly",					// Czech
     },
     {"Sources",                // English
     "Quellen",      			// Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Zdroje",					// Czech	
     },
    {"IGN",                     // English
     "IGNO",                    // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "IGN",						// Czech
     },
    {"LOAD",                    // English
     "LADE",                    // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "",
     },
    {"OK",                      // English
     "OK",                      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "OK",						// Czech	
     },
    {"FAIL",                    // English
     "FEHLER",                  // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Chyba",					// Czech
     },
    {"Please restart your ReelBox!",                    // English
     "Bitte starten Sie nun Ihre ReelBox neu!",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Pros�m restartujte Reelbox",		// Czech
     },
    {"and restart the ReelBox to be",               // English
     "versetzen und neu starten um sicher zu",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "restartovat k ulo�en� dat",		// Czech
     },
    {"sure that all changes take effect!",                    // English
     "stellen, dass alle �nderungen wirksam werden!",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                        // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Ujist�te se, �e v�echny zm�ny jsou vpo��dku!",		// Czech
    },
    {"Please go into deep standby, restart",                    // English
     "Bitte versuchen Sie es nochmal, nachdem",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                         // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Pros�m vypn�te do Standby, restart",		// Czech
    },
    {"the ReelBox and try the update again.",       // English
     "die ReelBox einmal im DeepStandby war.",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu�s
     "",                        // Fran�ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa�ol
     "",                        // ��������
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal�
     "",                         // ������� (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Zkuste Reelbox Updatovat znovu",		// Czech
    },
    {"Reboot ?",                // English
     "Neustart ?",      		// Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu?s
     "",                        // Fran?ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa?ol
     "",                        // ????????
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal?
     "",                        // ??????? (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Reboot ?",				// Czech
    },
    {"Rebooting, please wait...",                    // English
     "Neustart wird ausgef�hrt - bitte warten...",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu?s
     "",                        // Fran?ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa?ol
     "",                        // ????????
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal?
     "",                         // ??????? (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Restartuji..Pros�m �ekejte!",
    },
    {"Optional",                // English
     "Optional",                // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu?s
     "",                        // Fran?ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa?ol
     "",                        // ????????
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal?
     "",                        // ??????? (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Voliteln�",				// Czech
    },
    {"Software - Optional packages",                // English
     "Software - optionale Pakete",                // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu?s
     "",                        // Fran?ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa?ol
     "",                        // ????????
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal?
     "",                        // ??????? (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Software - Voliteln� moduly",		// Czech
    },
    {"Optional Software Setup",                // English
     "Optionale Software Setup",                // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu?s
     "",                        // Fran?ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa?ol
     "",                        // ????????
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal?
     "",                        // ??????? (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Voliteln� software setup",		// Czech
     },
    {"Recording is running, restart anyway ?",         // English
     "Aufzeichnung l�uft, wirklich neustarten ?",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu?s
     "",                        // Fran?ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa?ol
     "",                        // ????????
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal?
     "",                        // ??????? (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Prob�h� nahr�v�n�. Opravdu chcete restartovat ?",
    },
    {"Recording is running !",         // English
     "Aufzeichnung l�uft!",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu?s
     "",                        // Fran?ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa?ol
     "",                        // ????????
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal?
     "",                        // ??????? (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Prob�h� nahr�v�n�. Opravdu chcete restartovat ?",
    },
    {"Updates available! Press OK to update now.",                    // English
     "Softwareupdates verf�gbar. Jetzt installieren?",      // Deutsch
     "",                        // Slovenski
     "",                        // Italiano
     "",                        // Nederlands
     "",                        // Portugu?s
     "",                        // Fran?ais
     "",                        // Norsk
     "",                        // suomi
     "",                        // Polski
     "",                        // Espa?ol
     "",                        // ????????
     "",                        // Svenska
     "",                        // Romaneste
     "",                        // Magyar
     "",                        // Catal?
     "",                        // ??????? (Russian)
     "",                        // Hrvatski (Croatian)
     "",                        // Eesti
     "",                        // Dansk
     "Je mo�n� updatovat. Stisn�te OK pro update.",		// Czech
     },
	 {"Press OK to abort update.",                    // English
  "Dr�cken Sie OK um abzubrechen.",      // Deutsch
  "",                        // Slovenski
  "",                        // Italiano
  "",                        // Nederlands
  "",                        // Portugu?s
  "",                        // Fran?ais
  "",                        // Norsk
  "",                        // suomi
  "",                        // Polski
  "",                        // Espa?ol
  "",                        // ????????
  "",                        // Svenska
  "",                        // Romaneste
  "",                        // Magyar
  "",                        // Catal?
  "",                        // ??????? (Russian)
  "",                        // Hrvatski (Croatian)
  "",                        // Eesti
  "",                        // Dansk
  "Stisn�te OK pro zru�en� update",		// Czech
	 },
  {"Aborting...",                    // English
  "Breche Vorgang ab...",      // Deutsch
  "",                        // Slovenski
  "",                        // Italiano
  "",                        // Nederlands
  "",                        // Portugu?s
  "",                        // Fran?ais
  "",                        // Norsk
  "",                        // suomi
  "",                        // Polski
  "",                        // Espa?ol
  "",                        // ????????
  "",                        // Svenska
  "",                        // Romaneste
  "",                        // Magyar
  "",                        // Catal?
  "",                        // ??????? (Russian)
  "",                        // Hrvatski (Croatian)
  "",                        // Eesti
  "",                        // Dansk
  "Zru�en�..",				 // Czech
  },
  {"Please check your internet connection.",                    // English
  "Pr�fen Sie bitte Ihre Internetverbindung.",      // Deutsch
  "",                        // Slovenski
  "",                        // Italiano
  "",                        // Nederlands
  "",                        // Portugu?s
  "",                        // Fran?ais
  "",                        // Norsk
  "",                        // suomi
  "",                        // Polski
  "",                        // Espa?ol
  "",                        // ????????
  "",                        // Svenska
  "",                        // Romaneste
  "",                        // Magyar
  "",                        // Catal?
  "",                        // ??????? (Russian)
  "",                        // Hrvatski (Croatian)
  "",                        // Eesti
  "",                        // Dansk
  "",				 // Czech
  },
  {NULL}
};
