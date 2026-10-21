#include <revolution/GX/GXInit.h>
#pragma force_active on

void fn_801F12E0(unsigned char* a, int* b) {
    *a = gxdt->linePtWidth;
    *b = (gxdt->linePtWidth >> 16) & 0x7;
}
