#include <string.h>
#pragma force_active on

void fn_8020C6CC(char *dst, const char *src) {
    int i;
    const char *p;
    if (src[0] == '/' && src[1] == '\0') {
        dst[0] = '/';
        dst[1] = '\0';
        return;
    }
    i = strlen(src) - 1;
    p = src + i;
    for (; i >= 0; i--, p--) {
        if (*p == '/') {
            if (i != 0) {
                strncpy(dst, src, i);
                dst[i] = '\0';
                return;
            }
            dst[0] = '/';
            dst[1] = '\0';
            return;
        }
    }
}