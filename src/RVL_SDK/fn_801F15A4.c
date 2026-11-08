#include <revolution/GX/GXInit.h>
#pragma force_active on

typedef struct Cmd {
    unsigned int cmd : 8;
    unsigned int pad : 14;
    unsigned int idx : 10;
} Cmd;

unsigned int fn_801F15A4(int arg0) {
    union { unsigned int w; Cmd c; } u;
    u.w = 0;
    u.c.idx = ((arg0 * 2) & 0xFFFE) >> 5;
    u.c.cmd = 0x4D;
    *(unsigned int*)((unsigned char*)__GXData + 0x238) = u.w;
    return u.w;
}
