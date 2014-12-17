/*
 * i18n.c: Internationalization
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id: i18n.c,v 1.4 2005/01/01 22:11:13 schmitzj Exp $
 *
 */

#include "i18n.h"

const tI18nPhrase tlPhrases[] = {
  { "Timer Timeline", // English
    "Timer Zeitleiste", // Deutsch
    "", // Slovenski
    "Tabella Timers", // Italiano
    "Timers tijdlijst", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "Aikajana", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "Show timer overview and collisions", // English
    "", // Deutsch
    "", // Slovenski
    "Mostra controllo Iimer ed eventuali conflitti", // Italiano
    "Toon timers overzicht en conflicten", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "N�ytt�� p��llekk�iset ajastimet", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "No conflicts", // English
    "Keine Konflikte", // Deutsch
    "", // Slovenski
    "Non ci sono conflitti", // Italiano
    "Geen conflicten", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "Ei p��llekk�isyyksi�", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "Conflict on", // English
    "Konflikt am", // Deutsch
    "", // Slovenski
    "Conflitto al", // Italiano
    "Conflict op", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "P��llekk�isyys", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "Repeating conflict on", // English
    "Wiederh. Konflikt an", // Deutsch
    "", // Slovenski
    "Conflitto ripetuto al", // Italiano
    "Herhaald conflict op", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "Toistuva p��llekk�isyys", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "same input device", // English
    "gleiche Eingangs-Device", // Deutsch
    "", // Slovenski
    "stessa periferica in ingresso", // Italiano
    "Zelfde ingangsdevice", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "sama vastaanotin", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "(today)", // English
    "(heute)", // Deutsch
    "", // Slovenski
    "(oggi)", // Italiano
    "(vandaag)", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "(t�n��n)", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "Cursor up/down/left/right+Nums", // English
    "Taste auf/ab/links/rechts+Zahlen", // Deutsch
    "", // Slovenski
    "Cursore su/giu'/sinistra/destra+Numeri", // Italiano
    "Cursor op/neer/links/rechts+nummers", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "Yl�s/Alas/Vasen/Oikea/Numeron�pp�imet", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "Ignore primary interface", // English
    "Ignoriere prim�res Interface", // Deutsch
    "", // Slovenski
    "Ignorare interfaccia primaria", // Italiano
    "Negeer primaire interface", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "J�t� p��vastaanotin huomioimatta", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "Prio", // English
    "Priorit�t", // Deutsch
    "", // Slovenski
    "Priorita'", // Italiano
    "Prioriteit", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "prioriteetti", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { "Timeline", // English
    "Timer Zeitleiste", // Deutsch
    "", // Slovenski
    "", // Italiano
    "", // Nederlands
    "", // Portugu�s
    "", // Fran�ais
    "", // Norsk
    "", // suomi
    "", // Polski
    "", // Espa�ol
    "", // ��������
    "", // Svenska
    "", // Romaneste
    "", // Magyar
    "", // Catal�
    ""  // ������� (Russian)
    "", // Hrvatski (Croatian)
    "", // Eesti
    "", // Dansk
    "",
  },
  { NULL }
  };
