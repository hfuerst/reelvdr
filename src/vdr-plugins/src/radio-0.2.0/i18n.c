/*
 * i18n.c: Internationalization
 *
 * See the README file for copyright information and how to reach the author.
 *
 */

#include "i18n.h"

const tI18nPhrase Phrases[] = {
  { "RDS-Radiotext",	// English
    "RDS-Radiotext",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "RDS",		// Fran�ais
    "",// Norsk
    "RDS-teksti",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Radio Background-Image/RDS-Text",			// English
    "Hintergr.Bilder/RDS-Text f�r Radiosender",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Image de fond pour les radio/RDS-Texte",		// Fran�ais
    "",// Norsk
    "Taustakuva ja RDS-teksti radiokanaville",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Show RDS-Radiotext",	// English
    "Zeige RDS-Radiotext",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Afficher RDS",		// Fran�ais
    "",// Norsk
    "N�yt� RDS-teksti",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Radiotext",	// English
    "Radiotext",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "RDS",		// Fran�ais
    "",// Norsk
    "RDS-teksti",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "  [waiting ...]",	// English
    "  [warte ...]",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "  [attente ...]",	// Fran�ais
    "",// Norsk
    "  [odota ...]",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Activate",		// English
    "RDSText einschalten",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Activer",		// Fran�ais
    "",// Norsk
    "Aktiivinen",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText Function",		// English
    "RDSText Funktion",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Fonction de RDS-Texte",	// Fran�ais
    "",// Norsk
    "RDS-tekstin toiminto",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Position",		// English
    "RDSText Position",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Position OSD de RDS-Texte",	// Fran�ais
    "",// Norsk
    "RDS-tekstin sijainti",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Titlerow",	// English
    "RDSText Titelzeile",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Titre OSD de RDS-Texte",	// Fran�ais
    "",// Norsk
    "RDS-tekstin kappale",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Rows (1-5)",		// English
    "RDSText Zeilen (1-5)",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Ligne OSD de RDS-Texte (1-5)",	// Fran�ais
    "",// Norsk
    "RDS-tekstin rivim��r�",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Scrollmode",		// English
    "RDSText Scrollmodus",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Mode Scroll OSD de RDS-Texte ",	// Fran�ais
    "",// Norsk
    "RDS-tekstin vieritystapa",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Taginfo",		// English
    "RDSText Taginformation",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Tag info OSD de RDS-Texte",	// Fran�ais
    "",// Norsk
    "RDS-tekstin tunnistetiedot",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Backgr.Color",		// English
    "RDSText Hintergrundfarbe",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Couleur de fond OSD de RDS-Texte",	// Fran�ais
    "",// Norsk
    "RDS-tekstin taustav�ri",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Backgr.Transp.",		// English
    "RDSText Hintergr.Transparenz",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Fond transparent OSD de RDS-Texte",	// Fran�ais
    "",// Norsk
    "RDS-tekstin taustan l�pin�kyvyys",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Foregr.Color",			// English
    "RDSText Textfarbe",			// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Couleur du texte OSD de RDS-Texte",	// Fran�ais
    "",// Norsk
    "RDS-tekstin v�ri",				// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Display",		// English
    "RDSText Anzeige",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Affichage OSD de RDS-Texte",	// Fran�ais
    "",// Norsk
    "RDS-tekstin esitys",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Hide MainMenuEntry",			// English
    "Verstecke Hauptmenu-Eintrag",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Cacher l'entr�e dans le menu principal",	// Fran�ais
    "",// Norsk
    "Piilota valinta p��valikosta",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Top",		// English
    "Oben",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Haut",		// Fran�ais
    "",// Norsk
    "yl�reuna",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Bottom",		// English
    "Unten",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Bas",		// Fran�ais
    "",// Norsk
    "alareuna",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Black",		// English
    "Schwarz",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Noir",		// Fran�ais
    "",// Norsk
    "musta",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "White",		// English
    "Weiss",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Blanc",		// Fran�ais
    "",// Norsk
    "valkoinen",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Red",		// English
    "Rot",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Rouge",		// Fran�ais
    "",// Norsk
    "punainen",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Green",		// English
    "Gr�n",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Vert",		// Fran�ais
    "",// Norsk
    "vihre�",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Yellow",		// English
    "Gelb",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Jaune",		// Fran�ais
    "",// Norsk
    "keltainen",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Magenta",		// English
    "Magenta",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Magenta",		// Fran�ais
    "",// Norsk
    "magenta",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Blue",		// English
    "Blau",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Bleu",		// Fran�ais
    "",// Norsk
    "sininen",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Cyan",		// English
    "Cyan",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Cyan",		// Fran�ais
    "",// Norsk
    "syaani",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Transparent",	// English
    "Transparent",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Transparent",	// Fran�ais
    "",// Norsk
    "l�pin�kyv�",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Off",		// English
    "Aus",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Off",		// Fran�ais
    "",// Norsk
    "pois",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "about MainMenu",			// English
    "�ber Hauptmen�",			// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "A propos de menu principal",	// Fran�ais
    "",// Norsk
    "p��valikosta",			// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Automatic",	// English
    "Automatisch",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Automatique",	// Fran�ais
    "",// Norsk
    "automaattisesti",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDS-Text AutoOSD active",		// English
    "RDS-Text AutoOSD aktiviert",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "AutoOSD actif de RDS-Texte",	// Fran�ais
    "",// Norsk
    "RDS-tekstin esitys aktivoitu",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "only Text",		// English
    "nur Text",			// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Seulement le texte",	// Fran�ais
    "",// Norsk
    "vain teksti",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Text+TagInfo",		// English
    "Text+TagInfos",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Texte+Tag d'info",		// Fran�ais
    "",// Norsk
    "teksti+tunniste",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Artist :",		// English
    "Interpret :",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Artiste :",	// Fran�ais
    "",// Norsk
    "Esitt�j�   :",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Title  :",		// English
    "Titel        :",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Titre :",		// Fran�ais
    "",// Norsk
    "Kappale :",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "only, if some",		// English
    "nur, wenn vorhanden",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Seulement, si disponible",	// Fran�ais
    "",// Norsk
    "jos saatavilla",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "always",		// English
    "immer",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Toujours",		// Fran�ais
    "",// Norsk
    "aina",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "latest at Top",	// English
    "aktuelle Oben",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "En haut",		// Fran�ais
    "",// Norsk
    "yl�sp�in",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "latest at Bottom",	// English
    "aktuelle Unten",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "En bas",		// Fran�ais
    "",// Norsk
    "alasp�in",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "unknown program type",		// English
    "Unbekannte Programmart",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Type de programme inconnu",	// Fran�ais
    "",// Norsk
    "tuntematon ohjelmatyyppi",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "News",		// English
    "Nachrichten",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Nouvelles",	// Fran�ais
    "",// Norsk
    "uutiset",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Current affairs",		// English
    "Aktuelles",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Affaires courantes",	// Fran�ais
    "",// Norsk
    "ajankohtaista",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Information",	// English
    "Info",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Information",	// Fran�ais
    "",// Norsk
    "tiedote",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Sport",		// English
    "Sport",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Sport",		// Fran�ais
    "",// Norsk
    "urheilua",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Education",	// English
    "Bildung",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Education",	// Fran�ais
    "",// Norsk
    "opetusohjelmaa",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Drama",		// English
    "H�rspiel",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Drame",		// Fran�ais
    "",// Norsk
    "draamaa",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Culture",		// English
    "Kultur",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Culture",		// Fran�ais
    "",// Norsk
    "kulttuuria",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Science",		// English
    "Wissenschaft",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Science",		// Fran�ais
    "",// Norsk
    "tiedeohjelma",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Varied",		// English
    "Diverses",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Divers",		// Fran�ais
    "",// Norsk
    "sekalaista",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Pop music",	// English
    "Popmusik",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Musique Pop",	// Fran�ais
    "",// Norsk
    "pop-musiikkia",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Rock music",	// English
    "Rockmusik",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Musique Rock",	// Fran�ais
    "",// Norsk
    "rock-musiikkia",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "M.O.R. music", 		// English
    "Easy Listening u.�.",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Musique M.O.R.",		// Fran�ais
    "",// Norsk
    "taukomusiikkia",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Light classical",		// English
    "Leichte Klassik",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Classique facile",		// Fran�ais
    "",// Norsk
    "kevytt� klassista",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Serious classical",	// English
    "Ernste Klassik",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Classique s�rieux",	// Fran�ais
    "",// Norsk
    "klassista",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Other music",		// English
    "Sonstige Musik",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Autre musique",		// Fran�ais
    "",// Norsk
    "musiikkia",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Alarm",		// English
    "Alarm",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Alarme",		// Fran�ais
    "",// Norsk
    "h�t�tiedote",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Timeout (0-1440 min)",		// English
    "RDSText OSD-Timeout (0-1440 min)",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Timeout OSD de RDS-Texte (0-1440 min)",	// Fran�ais
    "",// Norsk
    "RDS-tekstin odotusaika (0-1440min)",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "min. timeout",	// English
    "Min. Timeout",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Min. timeout",	// Fran�ais
    "",// Norsk
    "min. odotusaika",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "no timeout",	// English
    "kein Timeout",     // Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Pas de timeout",	// Fran�ais
    "",// Norsk
    "ei odotusaikaa",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText StatusMsg (lcdproc & co)",			// English
    "RDSText StatusMeld. (lcdproc & co)",     		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Statut message de RDS-Texte (lcdproc & co)",	// Fran�ais
    "",// Norsk
    "RDS-tekstin toiminto laajennoksille",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "only Taginfo",		// English
    "nur TagInfos",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Seulement Tag Info",	// Fran�ais
    "",// Norsk
    "vain tunniste",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDS-Text: OSD Timeout, disabled ",		// English
    "RDS-Text: OSD Timeout, deaktiviert",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "RDS-Texte : D�sactiver timeout OSD",	// Fran�ais
    "",// Norsk
    "RDS-teksti: ei odotusaikaa",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RTplus",		// English
    "RTplus",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "RTplus",		// Fran�ais
    "",// Norsk
    "RTplus",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Playlist",		// English
    "Titelliste",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Playlist",		// Fran�ais
    "",// Norsk
    "Soittolista",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Sports",		// English
    "Sport",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Sports",		// Fran�ais
    "",// Norsk
    "Urheilu",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Weather",		// English
    "Wetter",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "M�t�o",		// Fran�ais
    "",// Norsk
    "S��",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Stockmarket",	// English
    "B�senkurse",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Bourse",		// Fran�ais
    "",// Norsk
    "P�rssikurssit",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Other",		// English
    "Sonstiges",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Autre",		// Fran�ais
    "",// Norsk
    "Sekalaiset",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Radiotext",	// English
    "Radiotext",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Radio Texte",	// Fran�ais
    "",// Norsk
    "Radioteksti",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RTplus Memory  since",	// English
    "RTplus Speicher  seit",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "M�moire de RTplus depuis",	// Fran�ais
    "",// Norsk
    "RTplus-muisti  alkaen",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Programme",	// English
    "Pogramminfo",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Programme",	// Fran�ais
    "",// Norsk
    "Ohjelma",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Station",		// English
    "Sendername",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Station",		// Fran�ais
    "",// Norsk
    "Asema",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Now",		// English
    "Jetzt",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Maintenant",	// Fran�ais
    "",// Norsk
    "Nyt",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "...Part",		// English
    "...Detail",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "...D�tail",	// Fran�ais
    "",// Norsk
    "...osa",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Next",		// English
    "Demn�chst",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Suivant",		// Fran�ais
    "",// Norsk
    "Seuraavaksi",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Host",		// English
    "Moderator",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Animateur",	// Fran�ais
    "",// Norsk
    "Juontaja",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Edit.Staff",	// English
    "Person(en)",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Personne",		// Fran�ais
    "",// Norsk
    "Henkil�kunta",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Homepage",		// English
    "Homepage",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Page d'accueil",	// Fran�ais
    "",// Norsk
    "Kotisivu",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Interactivity",		// English
    "Interaktiv (tu' was :)",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Interactivit�",		// Fran�ais
    "",// Norsk
    "Interaktiivinen",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Phone-Hotline",		// English
    "Tel.-Hotline",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "T�l�phone hotline",	// Fran�ais
    "",// Norsk
    "Suoralinja puhelimelle",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Phone-Studio",		// English
    "Tel.-Studio",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "T�l�phone studio",		// Fran�ais
    "",// Norsk
    "Puhelin studioon",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Email-Hotline",		// English
    "EMail-Hotline",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "E-mail hotline",		// Fran�ais
    "",// Norsk
    "Suoralinja s�hk�postille",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Email-Studio",		// English
    "EMail-Studio",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "E-mail studio",		// Fran�ais
    "",// Norsk
    "S�hk�posti studioon",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Info",			// English
    "weitere Information",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "D'autres information",	// Fran�ais
    "",// Norsk
    "Lis�tiedot",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "News",		// English
    "Nachrichten",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Informations",	// Fran�ais
    "",// Norsk
    "Uutiset",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "NewsLocal",		// English
    "Nachricht.Lokal",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Information local",	// Fran�ais
    "",// Norsk
    "Paikallisuutiset",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "DateTime",		// English
    "Datum-Zeit",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Date-Heure",	// Fran�ais
    "",// Norsk
    "Ajankohtaista",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Traffic",		// English
    "Verkehr",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Traffic",		// Fran�ais
    "",// Norsk
    "Liikenne",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Alarm",		// English
    "Alarm (!)",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Alamre",		// Fran�ais
    "",// Norsk
    "H�lytys",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Advertising",	// English
    "Hinweis/Reklame",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Publicit�",	// Fran�ais
    "",// Norsk
    "Mainos",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Url",		// English
    "Url/Webseite",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Url",		// Fran�ais
    "",// Norsk
    "Linkki",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Exit",		// English
    "Beenden",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Sortir",		// Fran�ais
    "",// Norsk
    "Lopeta",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Time",		// English
    "Zeit",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Temps",		// Fran�ais
    "",// Norsk
    "Kellonaika",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Title",		// English
    "Titel",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Titre",		// Fran�ais
    "",// Norsk
    "Kappale",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Artist",		// English
    "Interpret",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Artiste",		// Fran�ais
    "",// Norsk
    "Esitt�j�",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "last seen Radiotext",		// English
    "die letzten Radiotexte",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Dernier Radio-texte",		// Fran�ais
    "",// Norsk
    "viimeksi n�hty radioteksti",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Refresh Off",		// English
    "Aktualis. Aus",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Arr�ter actualisation",	// Fran�ais
    "",// Norsk
    "�l� p�ivit�",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Refresh On",		// English
    "Aktualis. Ein",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "D�marrer actualisation",	// Fran�ais
    "",// Norsk
    "P�ivit�",			// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Back",		// English
    "Zur�ck",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Retour",		// Fran�ais
    "",// Norsk
    "Takaisin",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSplus Memorynumber (10-99)",	// English
    "RDSplus Speicheranzahl (10-99)",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "M�moire RDSplus (10-99)",		// Fran�ais
    "",// Norsk
    "RDSplus-muistipaikka (10-99)",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RTplus-File saved",		// English
    "RTplus-Datei gespeichert",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Sauv� fichier TTplus",		// Fran�ais
    "",// Norsk
    "RTplus-tiedosto tallennettu",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText OSD-Skincolors used",		// English
    "RDSText OSD-Skinfarben benutzen",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Couleur du skin utilis� de RDS-texte",	// Fran�ais
    "",// Norsk
    "K�yt� RDS-tekstille ulkoasun v�rej�",	// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Lottery",		// English
    "Lotterie",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "Loterie",		// Fran�ais
    "",// Norsk
    "Arvonta",		// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDS-RaSS: Records closed, Slideshow activ",	// English
    "RDS-RaSS: Archiv geschlossen, Bildlauf aktiv",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "",// Fran�ais
    "",// Norsk
    "",// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDS-RaSS: Slideshow detected & startet",		// English
    "RDS-RaSS: Bildlauf gefunden und gestartet",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "",// Fran�ais
    "",// Norsk
    "",// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "[0] Contents",	// English
    "[0] Inhalt",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "",// Fran�ais
    "",// Norsk
    "",// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "Records",		// English
    "Archiv",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "",// Fran�ais
    "",// Norsk
    "",// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "with <0>",		// English
    "mit  <0>",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "",// Fran�ais
    "",// Norsk
    "",// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RDSText RaSS-Function",		// English
    "RDSText RaSS-Funktion",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "",// Fran�ais
    "",// Norsk
    "",// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RaSS only",	// English
    "RaSS alleine",	// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "",// Fran�ais
    "",// Norsk
    "",// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { "RaSS+Text mixed",		// English
    "Text �ber RaSS",		// Deutsch
    "",// Slovenski
    "",// Italiano
    "",// Nederlands
    "",// Portugu�s
    "",// Fran�ais
    "",// Norsk
    "",// suomi
    "",// Polski
    "",// Espa�ol
    "",// ��������
    "",// Svenska
    "",// Romaneste
    "",// Magyar
    "",// Catal�
    "" // �������
  },
  { NULL }
};
