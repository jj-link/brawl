#include <string.h>
#pragma force_active on

extern "C" {
void fn_801C7090(char* dst, const char* src) {
    unsigned int len = strlen(src);
    unsigned int n = len;
    if ((src + len)[-1] != '/') {
        *(dst + n + 8) = '/';
        n = len + 1;
    }
    *(dst + n + 8) = 0;
    strncpy(dst + 8, src, len);
}
}
