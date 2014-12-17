/*
 * config.c: SAT>IP plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 */

#include "discover.h"
#include "config.h"

cSatipConfig SatipConfig;

cSatipConfig::cSatipConfig(void)
: operatingModeM(eOperatingModeLow),
  eitScanM(1),
  useBytesM(1)
{
  for (unsigned int i = 0; i < ARRAY_SIZE(disabledFiltersM); ++i)
      disabledFiltersM[i] = -1;
  memset(configDirectoryM, 0, sizeof(configDirectoryM));
  availableSourcesM = NULL;
}

unsigned int cSatipConfig::GetDisabledFiltersCount(void) const
{
  unsigned int n = 0;
  while ((n < ARRAY_SIZE(disabledFiltersM) && (disabledFiltersM[n] != -1)))
        n++;
  return n;
}

int cSatipConfig::GetDisabledFilters(unsigned int indexP) const
{
  return (indexP < ARRAY_SIZE(disabledFiltersM)) ? disabledFiltersM[indexP] : -1;
}

void cSatipConfig::SetDisabledFilters(unsigned int indexP, int numberP)
{
  if (indexP < ARRAY_SIZE(disabledFiltersM))
     disabledFiltersM[indexP] = numberP;
}

void cSatipConfig::SetConfigDirectory(const char *directoryP)
{
  debug("cSatipConfig::%s(%s)", __FUNCTION__, directoryP);
  ERROR_IF(!realpath(directoryP, configDirectoryM), "Cannot canonicalize configuration directory");
}
