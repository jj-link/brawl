#pragma force_active on
#include <revolution/BASE/PPCArch.h>

extern unsigned int __peReg;

void fn_801F0B24(int arg0) {
    unsigned short *reg = (unsigned short *)__peReg;
    reg[4] = (unsigned short)(__rlwimi(0, arg0, 0, 30, 31) | 4);
}
