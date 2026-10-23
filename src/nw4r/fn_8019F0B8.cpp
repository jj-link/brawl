#include <types.h>
#pragma force_active on

extern "C" {
void fn_801EC158(void*);
void fn_80162BD0(void*);
}

extern "C" void* fn_8019F0B8(void* arg0) {
    u8* base = (u8*)arg0;
    u8* p31;
    u8* p30;
    u8* p29;
    u8* p28;
    u32 i;

    *(u16*)base = 0;
    *(u16*)(base + 2) = 0;
    fn_801EC158(base + 4);

    p31 = base + 0x34;
    p30 = base + 0x634;
    p29 = base + 0xE34;
    p28 = base + 0x1434;
    i = 0;

    do {
        fn_801EC158(p31);
        fn_80162BD0(p30);
        fn_801EC158(p29);
        fn_801EC158(p28);
        i++;
        p31 += 0x30;
        p30 += 0x40;
        p29 += 0x30;
        p28 += 0x30;
    } while (i < 0x20);

    return arg0;
}
