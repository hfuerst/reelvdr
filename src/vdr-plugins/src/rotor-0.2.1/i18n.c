/*
 * i18n.c: Internationalization
 *
 * See the README file for copyright information and how to reach the author.
 * Russian: Vyacheslav Dikonov <sdiconov@mail.ru>
 *
 */

#include "i18n.h"

const tI18nPhrase Phrases[] = {
  { "Drive West",
    "Nach Westen",
    "",// TODO
    "",// TODO
    "Naar West",
    "",// TODO
    "Aller Ouest",
    "",// TODO
    "Ohjaa l�nteen",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "�� �����",
  },
  { "Drive East",
    "Nach Osten",
    "",// TODO
    "",// TODO
    "Naar Oost",
    "",// TODO
    "Aller Est",
    "",// TODO
    "Ohjaa it��n",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "�� ������",
  },
  { "Halt",
    "Anhalten",
    "",// TODO
    "",// TODO
    "Stop",
    "",// TODO
    "Arr�t",
    "",// TODO
    "Pys�yt�",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "����",
  },
  { "Steps",
    "Schritte",
    "",// TODO
    "",// TODO
    "Stappen",
    "",// TODO
    "Incr�ment",
    "",// TODO
    "askelta",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "���(��) ��",
  },
  { "Recalc",
    "Neuberechnen",
    "",// TODO
    "",// TODO
    "Herbereken",
    "",// TODO
    "Recalc",
    "",// TODO
    "Laske uudelleen",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "�����������",
  },
  { "Goto",
    "Gehe zu",
    "",// TODO
    "",// TODO
    "Ga naar",
    "",// TODO
    "Aller �",
    "",// TODO
    "Siirry",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "�������",
  },
  { "Store",
    "Speichere",
    "",// TODO
    "",// TODO
    "Opslaan",
    "",// TODO
    "Enregistrer",
    "",// TODO
    "Tallenna",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "���������",
  },
  { "Limits off",
    "Limits aus",
    "",// TODO
    "",// TODO
    "Limiet uit",
    "",// TODO
    "D�sactiver Limites",
    "",// TODO
    "Ei rajoituksia",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "��������� �������",
  },
  { "Set East Limit",
    "Ost-Limit",
    "",// TODO
    "",// TODO
    "Zet Oost Limiet",
    "",// TODO
    "Limite Est",
    "",// TODO
    "Aseta rajoitus it��n",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "��������� ������",
  },
  { "Set West Limit",
    "West-Limit",
    "",// TODO
    "",// TODO
    "Zet West Limiet",
    "",// TODO
    "Limite Ouest",
    "",// TODO
    "Aseta rajoitus l�nteen",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "�������� ������",
  },
  { "Enable Limits",
    "Limits ein",
    "",// TODO
    "",// TODO
    "Limiet's in",
    "",// TODO
    "Activer Limites",
    "",// TODO
    "K�yt� rajoituksia",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "�������� �������",
  },
  { "Position",
    "Position",
    "",// TODO
    "",// TODO
    "Positie",
    "",// TODO
    "",
    "",// TODO
    "Sijainti",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",
  },
  { "Tuner",
    "Tuner",
    "",// TODO
    "",// TODO
    "Tuner",
    "",// TODO
    "",
    "",// TODO
    "",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",
  }, 
  { "Card, connected with motor",
    "Karte, die mit Motor verbunden ist",
    "",// TODO
    "",// TODO
    "Kaart, met motor verbonden",
    "",// TODO
    "Carte, connect�e au moteur",
    "",// TODO
    "Moottoriin kytketty DVB-kortti",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "����� ����������� � ��������",
  },
  { "Repeat DiSEqC-Commands?",
    "DiSEqC-Befehle wiederholen?",
    "",// TODO
    "",// TODO
    "DiSEqC-Commando's herhalen?",
    "",// TODO
    "R�p�ter Commandes DiSEqc?",
    "",// TODO
    "Toista DiSEqC-komennot",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "��������� ������� DiSEqC?",
  },
  { "Are you sure?",
    "Sind sie sicher?",
    "",// TODO
    "",// TODO
    "Is het zeker?",
    "",// TODO
    "Etes vous sur?",
    "",// TODO
    "Oletko varma?",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "�� �������?",
  },
  { "Not in DISEQC.CONF",
    "Kein Eintrag in DISEQC.CONF",
    "",// TODO
    "",// TODO
    "Niet in DISEQC.CONF",
    "",// TODO
    "Pas dans DISEQC.CONF",
    "",// TODO
    "Ei l�ydy DISEQC.CONF-tiedostosta",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "����������� � diseqc.conf",
  },
  { "Frequency",
    "Frequenz",
    "",// TODO
    "",// TODO
    "Frequentie",
    "",// TODO
    "Fr�quence",
    "",// TODO
    "Taajuus",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "�������",
  },
  { "Symbolrate",
    "Symbolrate",
    "",// TODO
    "",// TODO
    "Symbolrate",
    "",// TODO
    "SymbolRate",
    "",// TODO
    "Symbolinopeus",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "����. ��������",
  },
  { "Scan",
    "Scannen",
    "",// TODO
    "",// TODO
    "Scannen",
    "",// TODO
    "",
    "",// TODO
    "",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",
  },
  { "Rotor",
    "Rotor",
    "",// TODO
    "",// TODO
    "Rotor",
    "",// TODO
    "Motorisation",
    "",// TODO
    "Moottori",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "����������",
  },
  { "Steuerung eines Rotors",
    "Steuerung eines Rotors",
    "",// TODO
    "",// TODO
    "Aansturing van een Rotor",
    "",// TODO
    "",// TODO
    "",// TODO
    "Moottorin ohjaus",
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "",// TODO
    "���������� ������������",
  },
  { "My Longitude",
    "Mein L�ngengrad",
    "",
    "",
    "Lengtegraad",
    "",
    "Longitude",
    "",
    "Pituusaste",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "�������",
  },
  { "East",
    "Ost",
    "",
    "",
    "Oost",
    "",
    "Est",
    "",
    "it�ist�",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "������",
  },
  { "To East",
    "Nach Osten",
    "",
    "",
    "Naar Oost",
    "",
    "Est",
    "",
    "It��n",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "������",
  },
  { "West",
    "West",
    "",
    "",
    "West",
    "",
    "Ouest",
    "",
    "l�ntist�",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "�����",
  },
  { "To West",
    "Nach Westen",
    "",
    "",
    "Naar West",
    "",
    "Ouest",
    "",
    "L�nteen",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "�����",
  },
  { "My Latitude",
    "Mein Breitengrad",
    "",
    "",
    "Breedtegraad",
    "",
    "Latitude",
    "",
    "Leveysaste",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "������",
  },
  { "South",
    "S�d",
    "",
    "",
    "Zuid",
    "",
    "Sud",
    "",
    "etel�ist�",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "��",
  },
  { "North",
    "Nord",
    "",
    "",
    "Noord",
    "",
    "Nord",
    "",
    "pohjoista",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "�����",
  },
  { "Rotating Dish",
    "Sch�ssel dreht sich",
    "",
    "",
    "Schotel Draait",
    "",
    "",
    "",
    "K��nnet��n lautasta",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "����������� ������� �������",
  },
  { "Add Channel",
    "Add Channel",
    "",
    "",
    "Voeg Kanaal Toe",
    "",
    "",
    "",
    "Lis�� kanava",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Add All",
    "Add All",
    "",
    "",
    "Voeg Allen Toe",
    "",
    "",
    "",
    "Lis�� kaikki",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Satellite-Table",
    "Satelliten-Tabelle",
    "",
    "",
    "Satelliet-Tabelle",
    "",
    "",
    "",
    "Satelliittitaulukko",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Tuners connected with the steerable dish",
    "Tuner die mit der drehbaren Sch�ssel verbunden sind",
    "",
    "",
    "Tuner's verbonden met de draaibare Schotel",
    "",
    "",
    "",
    "Moottoroituun lautaseen kytketyt kortit",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Satellite",
    "Satellit",
    "",
    "",
    "Satelliet",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Satellite number",
    "Satelliten-Nummer",
    "",
    "",
    "Satelliet nummer",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Type of Control",
    "Steuerungsart",
    "",
    "",
    "Kontrole type",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Motor Control",
    "Motor-Einstellung",
    "",
    "",
    "Motor Kontrole",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Move",
    "Bewegung",
    "",
    "",
    "Verplaats",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Satellite Angle",
    "Satelliten Position",
    "",
    "",
    "Satelliet Positie",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "User",
    "Benutzer",
    "",
    "",
    "Gebruiker",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Installer",
    "Einrichter",
    "",
    "",
    "Installeer",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Goto Reference Position",
    "Referenz-Position",
    "",
    "",
    "Ga naar referentie punt",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "Goto Angular Position",
    "Drehe zur Position",
    "",
    "",
    "Ga naar positie",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "inactive",
    "inaktiv",
    "",
    "",
    "inaktief",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { "shared LNB",
    "mitbenutztes LNB",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
  },
  { NULL }
  };

