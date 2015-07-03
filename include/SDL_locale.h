#ifndef _SDL_locale_h_
#define _SDL_locale_h_

#include "SDL_stdinc.h"
#include "SDL_platform.h"

#include "begin_code.h"

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Get the country code for the current user.
 *
 * \return ISO country code.
 */
extern DECLSPEC char * SDLCALL LOC_GetCountryCode();

/**
 * \brief Get the prefered languages for the current user.
 *
 * Free the list with the LOC_FreeLanguageList macro.
 * \return allocated null terminated array of ISO languages in order of preference.
 */
extern DECLSPEC char ** SDLCALL LOC_GetLanguageList();

#define LOC_FreeLanguageList(LIST) \
if (LIST != NULL) { \
    char ** LIST_tmp = LIST; \
    while (*LIST_tmp != NULL) { \
        SDL_free(*LIST_tmp); \
		++LIST_tmp; \
    } \
    SDL_free(LIST); \
}

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif

#include "close_code.h"

#endif /* _SDL_locale_h_ */

/* vi: set ts=4 sw=4 expandtab: */
