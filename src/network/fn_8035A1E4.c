#include <stdarg.h>
#pragma force_active on

extern int snprintf(char *s, unsigned long n, const char *format, ...);
int vsnprintf(char *s, unsigned long n, const char *format, va_list arg);
extern void fn_80335638(int level, const char *fmt, ...);

extern char lbl_80415D08[];

void fn_8035A1E4(int level, const char *fmt, ...) {
    char buf[256];
    va_list args;
    int n;

    n = snprintf(buf, 0x100, lbl_80415D08 + 0x28, level);
    va_start(args, fmt);
    vsnprintf(buf + n, 0x100 - n, fmt, args);
    va_end(args);
    fn_80335638(0x08000000, buf);
}
