/**
 * util.c
 */

#include <string.h>

#include "util.h"

/**
 */
const char* get_base_name (const char* filename)
{
    char* base = strrchr(filename, '/');
    
    return base ? (base + 1) : filename;
}
