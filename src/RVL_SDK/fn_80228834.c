#include <stdarg.h>

typedef unsigned char u8;

int OSReport(const char *fmt, ...);
int vprintf(const char *fmt, va_list ap);
extern char lbl_8059ED88;
extern u8 lbl_805A0CD8;

#pragma force_active on
void fn_80228834(const char *fmt, ...) {
    va_list args;
    if (lbl_805A0CD8 != 0) {
        OSReport(&lbl_8059ED88);
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
    }
}
