#include <stdarg.h>
#pragma force_active on

int vsnprintf(char *s, unsigned long n, const char *format, va_list arg);

int fn_802819D0(char *buf, unsigned long n, const char *fmt, ...) {
    va_list args;
    int ret;

    va_start(args, fmt);
    ret = vsnprintf(buf, n, fmt, args);
    va_end(args);
    return ret;
}
