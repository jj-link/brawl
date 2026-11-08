#include <revolution/BASE/PPCArch.h>
#pragma force_active on

extern void *__peReg;

void fn_801F0BC0(int arg0, int arg1) {
    unsigned int v = __rlwimi(0, arg1, 0, 24, 31);
    v = __rlwimi(v, arg0, 8, 23, 23);
    *(unsigned short *)((char *)__peReg + 4) = (unsigned short)v;
}
