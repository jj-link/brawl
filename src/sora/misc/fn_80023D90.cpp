#include <types.h>
#pragma force_active on

extern "C" void fn_801F0CE8(int, void*);
extern "C" u8* lbl_8059FFFC;

extern "C" void fn_80023D90(void) {
    u8* p = lbl_8059FFFC;
    *(u32*)(p + ((u32)p[6] << 3) + 0xC) = 2;
    if (p[6] >= p[4]) {
        p[6] = 0;
    }
    u8* q = lbl_8059FFFC;
    *(u32*)(q + 0x20) = 1;
    fn_801F0CE8(0, q);
}
