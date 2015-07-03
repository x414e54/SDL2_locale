#include "../SDL_internal.h"

#ifdef SDL__LOCALE_DUMMY

char *
LOC_GetCountryCode()
{
    return NULL;
}

char **
LOC_GetLanguageList()
{
    return NULL;
}

#endif /* SDL_FILESYSTEM_DUMMY */

/* vi: set ts=4 sw=4 expandtab: */
