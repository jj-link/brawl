#include <string.h>
#pragma force_active on

int fn_803363D4(const char *key, char *out, const char *input, char delim)
{
    const char *p;
    const char *end;
    int len;

    if (out == 0)
        return -1;
    p = strchr(input, delim);
    if (p == 0)
        return -1;
    do {
        if (strncmp(p + 1, key, strlen(key)) == 0 && delim == p[1 + strlen(key)])
            break;
        p = strchr(p + 1, delim);
        if (p == 0)
            return -1;
        p = strchr(p + 1, delim);
        if (p == 0)
            return -1;
    } while (1);
    p = strchr(p + 1, delim);
    if (p == 0)
        return -1;
    end = strchr(p + 1, delim);
    if (end != 0)
        len = end - (p + 1);
    else
        len = strlen(p + 1);
    strncpy(out, p + 1, len);
    out[len] = 0;
    return len;
}