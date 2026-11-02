#pragma force_active on
#pragma peephole off
#include <revolution/GX/GXBump.h>

void fn_801F3194(void) {
    unsigned char *p = (unsigned char *)0xCC008000;
    __GXFlushTextureState();
    *p = 0x61;
    *(unsigned int *)p = 0x66001000;
    *p = 0x61;
    *(unsigned int *)p = 0x66001100;
    __GXFlushTextureState();
}