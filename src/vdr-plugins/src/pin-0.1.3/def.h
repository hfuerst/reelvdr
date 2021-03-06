/*
 * def.h
 *
 * See the README file for copyright information and how to reach the author.
 *
 */


#ifndef __DEF_H__
#define __DEF_H__

//***************************************************************************
// Includes
//***************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>      // memset
#include <time.h>

//***************************************************************************
// Public Declarations
//***************************************************************************

enum Misc
{
   success = 0,
   done    = success,
   fail    = -1,
   ignore  = -1,
   na      = -1,
   yes     = 1,
   no      = 0,
   TB      = 1
};

enum Sizes
{
   sizeStamp = 14,
   sizeTime = 6,
   sizeDate = 8,
   sizeHHMM = 4
};

enum TimeFact
{
   // Defintion

   tfMonthsPerYear    = 12,
   tfWeeksPerYear     = 52,
   tfDaysPerYear      = 365,
   tfDaysPerWeek      = 7,
   tfHoursPerDay      = 24,
   tfMinutesPerHour   = 60,
   tfSecondsPerMinute = 60,

   // Calculation
      
   tfSecondsPerHour  = tfMinutesPerHour * tfSecondsPerMinute,
   tfSecondsPerDay   = tfHoursPerDay * tfSecondsPerHour,
   tfSecondsPerYear  = tfDaysPerYear * tfSecondsPerDay,
   tfSecondsPerWeek  = tfDaysPerWeek * tfSecondsPerDay,
};

class DT
{
   public:

      typedef tm STime;

      static long lNow()
      {
         long lt = time(0);
         STime st;

         localtime_r(&lt, &st);
         lt = mktime(&st);

         lt -= timezone;                            // care timezone
         lt += st.tm_isdst ? tfSecondsPerHour : 0;  // care daylightsavingtime

         return lt;
      }

      static char* int2Hhmm(long lt, char* ct)
      {
         STime st;
         memset(&st, 0, sizeof(STime));
         gmtime_r(&lt, &st);
         
         sprintf(ct, "%2.2d%2.2d", st.tm_hour, st.tm_min);

         return ct;
      }

      static long hhmm2Int(const char* c)
      {
         long lt = 0;
         char ct[sizeHHMM+TB];

         if (strlen(c) != 4)
            return na;

         strcpy(ct, c);
         lt = atoi(ct+2) * 60;
         ct[2] = 0;
         lt += atoi(ct) * 60 * 60;

         return lt;
      }
};

//***************************************************************************
#endif // __DEF_H__
