#include <types.h>
#pragma force_active on
void fn_803BEB70(char *src, char *dst, int flags)
{
    int lower = flags & 8;
    char c;
    int i;
    int end;
    for (i = 0; i < 8; i++) {
        c = src[i];
        if (!c || c == '.') break;
        if (lower && c >= 'A' && c <= 'Z')
            dst[i] = c + 0x20;
        else
            dst[i] = c;
    }
    if (src[i] == '.') dst[i++] = '.';
    end = i + 3;
    for (; i < end; i++) {
        c = src[i];
        if (!c) break;
        if ((flags & 16) && c >= 'A' && c <= 'Z')
            dst[i] = c + 0x20;
        else
            dst[i] = c;
    }
    dst[i] = 0;
}