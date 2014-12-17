/*
 * DVD Player plugin for VDR
 *
 * Copyright (C) 2001.2002 Andreas Schultz <aschultz@warp10.net>
 *
 * This code is distributed under the terms and conditions of the
 * GNU GENERAL PUBLIC LICENSE. See the file COPYING for details.
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "i18n.h"

const char *ISO639code[] = {

  // Language ISO 639 codes for DVD

    "en",
    "de",
    "sl",
    "it",
    "nl",
    "pt",
    "fr",
    "no",
    "fi",
    "pl",
    "es",
    "el",
    "se",
    "ro",
    "hu",
    "ca",
    "ru",
    "hr",
    "et",
    "da",
    "",
};



const tI18nPhrase DvdPhrases[] = {

    {
    "Plugin.DVD$DVD",                                       // English
    "DVD",                                              // Deutsch
    "DVD",                                              // Slovenski
    "DVD",                                              // Italiano
    "DVD",                                              // Nederlands
    "DVD",                                              // Portugu�s
    "DVD",                                              // Fran�ais
    "DVD",                                              // Norsk
    "DVD",                                              // suomi
    "DVD",                                              // Polski
    "DVD",                                              // Espa�ol
    "DVD",                                              // �������� (Greek)
    "DVD",                                              // Svenska
    "DVD",                                              // Romaneste
    "DVD",                                              // Magyar
    "DVD",                                              // Catal�
    "DVD",                                              // ������� (Russian)
    "DVD",                                              // Hrvatski (Croatian)
    "DVD",                                              // Eesti
    "DVD",                                              // Dansk
    "",
    },
    {

    "Plugin.DVD$turn VDR into an (almost) full featured DVD player",    // English
    "",                                                             // Deutsch
    "",                                                             // Slovenski
    "",                                                             // Italiano
    "",                                                             // Nederlands
    "",                                                             // Portugu�s
    "",                                                             // Fran�ais
    "",                                                             // Norsk
    "DVD-soitin",                                                   // suomi
    "",                                                             // Polski
    "",                                                             // Espa�ol
    "",                                                             // �������� (Greek)
    "",                                                             // Svenska
    "",                                                             // Romaneste
    "",                                                             // Magyar
    "",                                                             // Catal�
    "",                                                             // ������� (Russian)
    "",                                                             // Hrvatski (Croatian)
    "",                                                             // Eesti
    "",                                                             // Dansk
    "",
    },
    {

    "Setup.DVD$Preferred menu language",                    // English
    "Bevorzugte Spache f�r Men�s",                      // Deutsch
    "",                                                 // Slovenski
    "menu - linguaggio preferito",                      // Italiano
    "Taalkeuze voor menu",                              // Nederlands
    "",                                                 // Portugu�s
    "Langage pr�f�r� pour les menus",                   // Fran�ais
    "",                                                 // Norsk
    "Haluttu valikkokieli",                             // suomi
    "",                                                 // Polski
    "Idioma preferido para los men�s",                  // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "",                                                 // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },
    {

    "Setup.DVD$Preferred audio language",                   // English
    "Bevorzugte Sprache f�r Dialog",                    // Deutsch
    "",                                                 // Slovenski
    "audio - linguaggio preferito",                     // Italiano
    "Taalkeuze voor geluid",                            // Nederlands
    "",                                                 // Portugu�s
    "Langage pr�f�r� pour le son",                      // Fran�ais
    "",                                                 // Norsk
    "Haluttu ��niraita",                                // suomi
    "",                                                 // Polski
    "Idioma preferido para el sonido",                  // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "",                                                 // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },
    {
    "Setup.DVD$Preferred subtitle language",                // English
    "Bevorzugte Spache f�r Untertitel",                 // Deutsch
    "",                                                 // Slovenski
    "sottotitoli - linguaggio preferito",               // Italiano
    "Taalkeuze voor ondertitels",                       // Nederlands
    "",                                                 // Portugu�s
    "Langage pr�f�r� pour les sous-titres",             // Fran�ais
    "",                                                 // Norsk
    "Haluttu tekstityskieli",                           // suomi
    "",                                                 // Polski
    "Idioma preferido para los subt�tulos",             // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "",                                                 // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },
    {
    "Setup.DVD$Player region code",                         // English
    "Regions Kode f�r Player",                          // Deutsch
    "",                                                 // Slovenski
    "region code del DVD player",                       // Italiano
    "Regiocode van Speler",                             // Nederlands
    "",                                                 // Portugu�s
    "Code r�gion du lecteur",                           // Fran�ais
    "",                                                 // Norsk
    "Soittimen aluekoodi",                              // suomi
    "",                                                 // Polski
    "C�digo de zona del lector",                        // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "",                                                 // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },
    {
    "Setup.DVD$Display subtitles",                          // English
    "Untertitel anzeigen",                              // Deutsch
    "",                                                 // Slovenski
    "Visualizza sottotitoli",                           // Italiano
    "Toon ondertitels",                                 // Nederlands
    "",                                                 // Portugu�s
    "Affiche les sous-titres",                          // Fran�ais
    "",                                                 // Norsk
    "N�yt� tekstitys",                                  // suomi
    "",                                                 // Polski
    "Mostrar subt�tulos",                               // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "",                                                 // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },
    {
    "Setup.DVD$Hide Mainmenu Entry",
    "Hauptmen�eintrag verstecken"                       // Deutsch
    "",                                                 // Slovenski
    "Nascondi voce men�",                               // Italiano
    "",                                                 // Nederlands
    "",                                                 // Portugu�s
    "",                                                 // Fran�ais
    "",                                                 // Norsk
    "Piilota valinta p��valikosta",                     // suomi
    "",                                                 // Polski
    "",                                                 // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "������ ������� � ������� ����",                    // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },
    {
    "Setup.DVD$ReadAHead",
    "ReadAHead",                                        // Deutsch
    "ReadAHead",                                        // Slovenski
    "ReadAHead",                                        // Italiano
    "ReadAHead",                                        // Nederlands
    "ReadAHead",                                        // Portugu�s
    "ReadAHead",                                        // Fran�ais
    "ReadAHead",                                        // Norsk
    "ReadAHead-toiminto",                               // suomi
    "ReadAHead",                                        // Polski
    "ReadAHead",                                        // Espa�ol
    "ReadAHead",                                        // �������� (Greek)
    "ReadAHead",                                        // Svenska
    "ReadAHead",                                        // Romaneste
    "ReadAHead",                                        // Magyar
    "ReadAHead",                                        // Catal�
    "ReadAHead",                                        // ������� (Russian)
    "ReadAHead",                                        // Hrvatski (Croatian)
    "ReadAHead",                                        // Eesti
    "ReadAHead",                                        // Dansk
    "ReadAHead",
    },
    {
    "Setup.DVD$Gain (analog)",
    "Verst�rkung (analog)",                                // Deutsch
    "Gain (analog)",                                       // Slovenski
    "Gain (analog)",                                       // Italiano
    "Gain (analog)",                                       // Nederlands
    "Gain (analog)",                                       // Portugu�s
    "Gain (analog)",                                       // Fran�ais
    "Gain (analog)",                                       // Norsk
    "��nen vahvistus (analoginen)",                        // suomi
    "Gain (analog)",                                       // Polski
    "Gain (analog)",                                       // Espa�ol
    "Gain (analog)",                                       // �������� (Greek)
    "Gain (analog)",                                       // Svenska
    "Gain (analog)",                                       // Romaneste
    "Gain (analog)",                                       // Magyar
    "Gain (analog)",                                       // Catal�
    "Gain (analog)",                                       // ������� (Russian)
    "Gain (analog)",                                       // Hrvatski (Croatian)
    "Gain (analog)",                                       // Eesti
    "Gain (analog)",                                       // Dansk
    "",
    },
    {
    "Error.DVD$Error opening DVD!",                         // English
    "Fehler beim �ffnen der DVD!",                      // Deutsch
    "",                                                 // Slovenski
    "",                                                 // Italiano
    "",                                                 // Nederlands
    "",                                                 // Portugu�s
    "",                                                 // Fran�ais
    "",                                                 // Norsk
    "DVD:n avaaminen ep�onnistui!",                     // suomi
    "",                                                 // Polski
    "",                                                 // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "",                                                 // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },
    {
    "Error.DVD$Error fetching data from DVD!",              // English
    "Fehler beim lesen von der DVD!",                   // Deutsch
    "",                                                 // Slovenski
    "",                                                 // Italiano
    "",                                                 // Nederlands
    "",                                                 // Portugu�s
    "",                                                 // Fran�ais
    "",                                                 // Norsk
    "DVD:n lukeminen ep�onnistui",                      // suomi
    "",                                                 // Polski
    "",                                                 // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "",                                                 // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },

    {
    "Error.DVD$Current subp stream not seen!",              // English
    "Der ausgew�hlte Untertitel ist nicht vorhanden!",  // Deutsch
    "",                                                 // Slovenski
    "",                                                 // Italiano
    "",                                                 // Nederlands
    "",                                                 // Portugu�s
    "",                                                 // Fran�ais
    "",                                                 // Norsk
    "Tekstitysraitaa ei havaita!",                      // suomi
    "",                                                 // Polski
    "",                                                 // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "",                                                 // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },
    {
    "Error.DVD$Current audio track not seen!",              // English
    "Die ausgew�hlte Audiospur ist nicht vorhanden!",   // Deutsch
    "",                                                 // Slovenski
    "",                                                 // Italiano
    "",                                                 // Nederlands
    "",                                                 // Portugu�s
    "",                                                 // Fran�ais
    "",                                                 // Norsk
    "��niraitaa ei havaita!",                           // suomi
    "",                                                 // Polski
    "",                                                 // Espa�ol
    "",                                                 // �������� (Greek)
    "",                                                 // Svenska
    "",                                                 // Romaneste
    "",                                                 // Magyar
    "",                                                 // Catal�
    "",                                                 // ������� (Russian)
    "",                                                 // Hrvatski (Croatian)
    "",                                                 // Eesti
    "",                                                 // Dansk
    "",
    },
    { NULL }

};

