/*
 *  $Id: i18n.c,v 1.5 2006/08/17 09:26:00 thomas Exp $
 */
 
#include "i18n.h"

const char *i18n_name = NULL;

const tI18nPhrase Phrases[] = {
	{	"VDR Streaming Server",	// English
		"VDR Streaming Server",	// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VDR-suoratoistopalvelin",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika / Greek
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"VTP Streaming Client",	// English
		"VTP Streaming Client",	// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VTP-suoratoistoasiakas ",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika / Greek
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Start VDR-to-VDR Server",// English
		"VDR-zu-VDR Server starten",// Deutsch
		"",											// Slovenski
		"Avvia il Server VDR-toVDR",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"K�ynnist� VDR-palvelin",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika / Greek
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Start HTTP Server",		// English
		"HTTP Server starten",	// Deutsch
		"",											// Slovenski
		"Avvia il Server HTTP", // Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"K�ynnist� HTTP-palvelin",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"HTTP Streamtype",		  // English
		"HTTP Streamtyp",	      // Deutsch
		"",											// Slovenski
		"Tipo di Stream HTTP",  // Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"HTTP-l�hetysmuoto",									// Suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Start Client",					// English
		"Client starten",				// Deutsch
		"",											// Slovenski
		"Avvia il Client",			// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"K�ynnist� VDR-asiakas",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"VDR-to-VDR Server Port",// English
		"Port des VDR-zu-VDR Servers",// Deutsch
		"",											// Slovenski
		"Porta del Server VDR-to-VDR",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VDR-palvelimen portti",								// Suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"HTTP Server Port",			// English
		"Port des HTTP Servers",// Deutsch
		"",											// Slovenski
		"Porta del Server HTTP",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"HTTP-palvelimen portti",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Maximum Number of Clients",// English
		"Maximalanzahl an Clients",// Deutsch
		"",											// Slovenski
		"Numero Massimo di Client",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Suurin sallittu asiakkaiden m��r�",							// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Remote IP",						// English
		"IP der Gegenseite",		// Deutsch
		"",											// Slovenski
		"Indirizzo IP del Server",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Et�koneen IP-osoite",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Remote Port",					// English
		"Port der Gegenseite",	// Deutsch
		"",											// Slovenski
		"Porta del Server Remoto",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Et�koneen portti",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Remote Streamtype",		// English
		"Streamtyp von Gegenseite",// Deutsch
		"",											// Slovenski
		"Tipo di Stream",       // Italiano (oppure Flusso ?)
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Et�koneen l�hetysmuoto",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Common Settings",		  // English
		"Allgemeines",          // Deutsch
		"",											// Slovenski
		"Settaggi Comuni",			// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Yleiset asetukset",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"VDR-to-VDR Server",		// English
		"VDR-zu-VDR Server",    // Deutsch
		"",											// Slovenski
		"Server VDR-to-VDR",		// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VDR-palvelin",										// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"HTTP Server",		      // English
		"HTTP Server",          // Deutsch
		"",											// Slovenski
		"Server HTTP",					// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"HTTP-palvelin",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"VDR-to-VDR Client",		// English
		"VDR-zu-VDR Client",    // Deutsch
		"",											// Slovenski
		"Client VDR-to-VDR",		// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VDR-asiakas",										// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Please restart VDR to activate changes",// English
		"Bitte starten Sie f�r die �nderungen VDR neu",// Deutsch
		"",											// Slovenski
		"Riavviare VDR per attivare i cambiamenti",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Aktivoi muutokset k�ynnist�m�ll� VDR uudelleen",					// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Synchronize EPG",			// English
		"EPG synchronisieren",	// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"P�ivit� ohjelmaopas",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Pause Live TV",			// English
		"Live-TV pausieren",			// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Pys�yt� suora TV-l�hetys",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Suspend behaviour",		// English
		"Pausierverhalten",			// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Pys�ytystoiminto",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Offer suspend mode",		// English
		"Pausieren anbieten",		// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"tyrkyt�",										// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Always suspended",			// English
		"Immer pausiert",				// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"aina",											// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Never suspended",			// English
		"Nie pausiert",					// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"ei koskaan",										// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Streaming Control",		// English
		"Streamkontrolle",			// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Suoratoiston hallinta",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Fetching recordings...",// English
		"Hole Aufnahmen...",		// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Haetaan tallenteita...",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Remote Recordings",		// English
		"Entfernte Aufnahmen",	// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Et�tallenteet",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Remote Timers",				// English
		"Entfernte Timer",			// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Et�ajastimet",										// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Suspend Server",				// English
		"Server pausieren",			// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Pys�yt� palvelin",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Server is suspended",	// English
		"Server ist pausiert",	// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Palvelin on pys�ytetty",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Couldn't suspend Server!",// English
		"Konnte Server nicht pausieren!",// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Palvelinta ei onnistuttu pys�ytt�m��n!",						// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Edit remote timer",		// English
		"Entfernten Timer editieren",// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Muokkaa et�ajastinta",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Timers not in sync! Try again...",// Englisch
		"Timer nicht synchron! Bitte wiederholen...",//Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Ajastimet eiv�t t�sm��! Yrit� uudelleen...",						// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Couldn't save timer! Try again...",// English
		"Konnte Timer nicht speichern! Bitte wiederholen...",// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Ajastimen tallennus ep�onnistui! Yrit� uudelleen...",					// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Couldn't delete timer! Try again...",// English
		"Konnte Timer nicht l�schen! Bitte wiederholen...",// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Ajastimen poistaminen ep�onnistui! Yrit� uudelleen...",				// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Server error! Try again...",// English
		"Serverfehler! Bitte wiederholen...",// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Palvelimessa virhe! Yrit� uudelleen...",						// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"MultiPID Streaming",		// English
		"Multiple PIDs streamen",// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Usean PID:in suoratoisto",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
	{	"Client may suspend",		// English
		"Client darf pausieren",// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Asiakas saa pys�ytt�� palvelimen",							// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
#if VDRVERSNUM >= 10300
		""                      // Russian
#endif
	},
        {       "Bind to IP",           // English
                "Binde an IP",// Deutsch
                "",                                                                                     // Slovenski
                "",                                                                                     // Italiano
                "",                                                                                     // Nederlands
                "",                                                                                     // Portugu�s
                "",                                                                                     // Fran�ais
                "",                                                                                     // Norsk
                "Sido osoitteeseen",                                                                    // suomi
                "",                                                                                     // Polski
                "",                                                                                     // Espa�ol
                "",                                                                                     // Ellinika
                "",                                                                                     // Svenska
                "",                                                                                     // Romaneste
                "",                                                                                     // Magyar
                "",                                                                                     // Catala
#if VDRVERSNUM >= 10300
                ""                      // Russian
#endif
        },
        {       "Remote Schedule",      // English
                "",// Deutsch
                "",                                                                                     // Slovenski
                "",                                                                                     // Italiano
                "",                                                                                     // Nederlands
                "",                                                                                     // Portugu�s
                "",                                                                                     // Fran�ais
                "",                                                                                     // Norsk
                "Et�koneen ohjelmaopas",                                                                // suomi
                "",                                                                                     // Polski
                "",                                                                                     // Espa�ol
                "",                                                                                     // Ellinika
                "",                                                                                     // Svenska
                "",                                                                                     // Romaneste
                "",                                                                                     // Magyar
                "",                                                                                     // Catala
#if VDRVERSNUM >= 10300
                ""                      // Russian
#endif
        },
        {       "Filter Streaming",     // English
                "Filter Streaming",// Deutsch
                "",                                                                                     // Slovenski
                "",                                                                                     // Italiano
                "",                                                                                     // Nederlands
                "",                                                                                     // Portugu�s
                "",                                                                                     // Fran�ais
                "",                                                                                     // Norsk
                "Suodatetun tiedon suoratoisto",                                                        // suomi
                "",                                                                                     // Polski
                "",                                                                                     // Espa�ol
                "",                                                                                     // Ellinika
                "",                                                                                     // Svenska
                "",                                                                                     // Romaneste
                "",                                                                                     // Magyar
                "",                                                                                     // Catala
#if VDRVERSNUM >= 10300
                ""                      // Russian
#endif
        },
        {       "Streaming active",     // English
                "Streamen im aktiv",// Deutsch
                "",                                                                                     // Slovenski
                "",                                                                                     // Italiano
                "",                                                                                     // Nederlands
                "",                                                                                     // Portugu�s
                "",                                                                                     // Fran�ais
                "",                                                                                     // Norsk
                "Suoratoistopalvelin aktiivinen", // suomi
                "",                                                                                     // Polski
                "",                                                                                     // Espa�ol
                "",                                                                                     // Ellinika
                "",                                                                                     // Svenska
                "",                                                                                     // Romaneste
                "",                                                                                     // Magyar
                "",                                                                                     // Catala
#if VDRVERSNUM >= 10300
                ""                      // Russian
#endif
        },
	{ NULL }
};
