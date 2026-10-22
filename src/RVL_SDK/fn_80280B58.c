#include <stdarg.h>
#pragma force_active on

typedef signed int s32;

extern void fn_8028196C(char* buf, unsigned long size, s32 arg, void* ap);
extern void fn_80280840(s32 p, char* buf);

void fn_80280B58(void* arg0, s32 arg1, ...) {
    char buf[0x400];
    va_list ap;
    va_start(ap, arg1);
    fn_8028196C(buf, 0x400, arg1, &ap);
    va_end(ap);
    fn_80280840(*(s32*)((char*)arg0 + 8), buf);
}
