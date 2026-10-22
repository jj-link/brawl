#include <stdarg.h>

int fn_803F88A4(char* s, const char* format, va_list arg);

#pragma force_active on
int fn_80281A5C(char* s, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    return fn_803F88A4(s, format, ap);
}
