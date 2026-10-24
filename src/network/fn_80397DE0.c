#include <stdarg.h>

void fn_80397E6C(int arg0, int arg1, va_list ap);

#pragma force_active on

void fn_80397DE0(int arg0, int arg1, ...) {
    va_list ap;
    va_start(ap, arg1);
    fn_80397E6C(arg0, arg1, ap);
}
