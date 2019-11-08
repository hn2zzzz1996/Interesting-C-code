#include <ctype.h>
#include <string.h>

static const char xd[] = 
    {"0123456789abcdefABCDEF"};
static const char xv[] = 
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15,
    10, 11, 12, 13, 14, 15};

for (value = 0; isxdigit(*s); ++s)
    value = (value << 4) + xv[strchr(xd, *s) - xd];