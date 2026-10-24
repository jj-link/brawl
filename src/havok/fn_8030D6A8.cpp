#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

extern "C" void fn_8027CD94(void* a, s32 b, s32 c);
extern "C" void fn_803127A8(void* a, u8* e, u8* p);

extern "C" void fn_8030D6A8(u8* self, u8* out) {
    s32 diff;
    s32 off;
    s32 eoff;
    s32 i;
    s32 flags;

    flags = *(u32*)(out + 8) & 0x3FFFFFFF;
    diff = *(s32*)(self + 0x74) - *(s32*)(self + 0xA0);
    if (flags < diff) {
        fn_8027CD94(out, diff, 0x20);
    }

    off = 0;
    i = 0;
    eoff = 0;
    *(s32*)(out + 4) = *(s32*)(self + 0x74) - *(s32*)(self + 0xA0);

    for (; i < *(s32*)(self + 0x74); i++) {
        u8* e = *(u8**)(self + 0x70) + eoff;
        if (!(*(u32*)(e + 0xC) & 1)) {
            u8* p = *(u8**)out + off;
            off += 0x20;
            fn_803127A8(self, e, p);
        }
        eoff += 0x10;
    }
}
