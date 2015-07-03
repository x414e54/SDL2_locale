#include "../SDL_internal.h"

#ifdef SDL_LOCALE_COCOA

#include <Foundation/Foundation.h>
#include <sys/types.h>

#include "SDL_error.h"
#include "SDL_stdinc.h"
#include "SDL_filesystem.h"

char *
LOC_GetCountryCode()
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    char *country_code = NULL;
    
    NSString *ns_code = [[NSLocale currentLocale] objectForKey: NSLocaleCountryCode];
    const char *tmp = (const char *)[ns_code UTF8String];

    if (tmp != NULL)
    {
        country_code = SDL_strdup(tmp);
    }
    
    [pool release];
    
    return country_code;
}

char **
LOC_GetLanguageList()
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    NSArray *preferredLanguages = [NSLocale preferredLanguages];
    
    size_t num_languages = [preferredLanguages count];
    char **languages = SDL_malloc((num_languages + 1) * sizeof(char *));
    languages[num_languages] = NULL;
    
    size_t index = 0;
    for (id ns_language in preferredLanguages) {
        const char *tmp = (const char *)[ns_language UTF8String];
        if (tmp != NULL && index < num_languages) {
            char *language = SDL_strdup(tmp);
            languages[index++] = language;
        }
    }
    
    [pool release];
    
    return languages;
}

#endif /* SDL_LOCALE_COCOA */

/* vi: set ts=4 sw=4 expandtab: */
