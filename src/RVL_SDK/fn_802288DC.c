#include <stdarg.h>

extern char lbl_8047E240[];
extern unsigned char lbl_8059ED84;

void OSReport(const char *fmt, ...);
int vprintf(const char *fmt, va_list ap);

#pragma force_active on
void fn_802288DC(const char *fmt, ...) {
    va_list args;

    if (lbl_8059ED84 != 0) {
        OSReport(lbl_8047E240);
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
    }
}
#pragma force_active reset
