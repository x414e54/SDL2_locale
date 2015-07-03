#include "../SDL_internal.h"

#ifdef SDL_LOCALE_UNIX

#include "SDL_stdinc.h"

const char *
find_end(const char *start, char delimiter)
{
    while (*start && (*start != delimiter) && ++start);
    return start;
}

size_t
count(const char *list, char c)
{
    size_t count = 1;
    while (*list) {
        if (*list == c) {
            ++count;
        }
        ++list;
    }
    return count;
}

char *
duplicate(const char *tmp, size_t length)
{
    char *out = NULL;
    if (length > 0) {
        out = SDL_malloc((length + 1) * sizeof(char));
        if (out != NULL) {
            SDL_memcpy(out, tmp, length);
            SDL_memset(out + length, 0, 1);
        }
    }
    return out;
}

char *
LOC_GetCountryCode()
{
    char* default_locale = NULL;
    
    const char* lang = SDL_getenv("LANG");

    if (lang != NULL)
    {
        lang = SDL_strchr(lang, '_');
        if (lang != NULL)
        {
            ++lang;
            size_t length = find_end(lang, '.') - lang;
            default_locale = duplicate(lang, length);
        }
    }
    
    return default_locale;
}

char **
LOC_GetLanguageList()
{
    char **languages = NULL;
    size_t num_languages = 0;
    const char* tmp = SDL_getenv("LANGUAGE");
    
    if (tmp != NULL) {
        // Count languages
        num_languages = count(tmp, ':');
        
        if (num_languages > 0) {
            languages = SDL_malloc((num_languages + 1) * sizeof(char*));
            if (languages != NULL) {
                size_t length = 0;
                size_t index = 0;
                while (*tmp && index < num_languages) {
                    length = find_end(tmp, ':') - tmp;
                    
                    char *language = duplicate(tmp, length);
                    if (language != NULL) {
                        languages[index++] = language;
                    }
                    
                    tmp += length;
                    if (*tmp == ':') {
                        ++tmp;
                    }
                }
                
                languages[index] = NULL;
            }
        }
    }
    
    if (num_languages == 0) {
        tmp = SDL_getenv("LANG");
        if (tmp != NULL) {
            languages = SDL_malloc((num_languages + 1) * sizeof(char*));
            
            size_t length = find_end(tmp, '_') - tmp;
            char *language = duplicate(tmp, length);
            if (language != NULL) {
                languages[0] = language;
                ++num_languages;
            }
            languages[num_languages] = NULL;
        }
    }
    
    return languages;
}

#endif /* SDL_LOCALE_UNIX */

/* vi: set ts=4 sw=4 expandtab: */
