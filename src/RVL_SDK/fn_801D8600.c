#include <stdarg.h>

void vprintf(const char* fmt, va_list args);

#pragma force_active on
void OSReport(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    vprintf(msg, args);
    va_end(args);
}
#pragma force_active reset
