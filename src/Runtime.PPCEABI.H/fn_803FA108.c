#include "lib/BrawlHeaders/OpenRVL/include/stl/stdarg.h"
#pragma force_active on

typedef struct __InStrCtrl {
    const char* NextChar;
    int NullCharDetected;
} __InStrCtrl;

extern int fn_803FA078(void*, int, int);
extern int fn_803F9318(int (*)(void*, int, int), void*, const char*, va_list, int);

int sscanf(const char* s, const char* format, ...) {
    va_list ap;
    __InStrCtrl isc;
    va_start(ap, format);
    isc.NextChar = s;
    if (s == 0 || *s == '\0')
        return -1;
    isc.NullCharDetected = 0;
    return fn_803F9318(fn_803FA078, &isc, format, ap, 0);
}
