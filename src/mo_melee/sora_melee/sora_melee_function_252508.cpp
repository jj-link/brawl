#include <types.h>
#pragma force_active on
extern "C" void fn_27_2450E4(u8* self);

extern "C" void fn_27_252508(u8* self, s32 idx) {
    *(s32*)(self + 0xE0) = 0;
    *(s32*)(self + 0xE8) = 0;
    switch (idx) {
    case 0:
        self[0xD5] = 0;
        self[0xD6] = 0;
        break;
    case 1:
        self[0xD5] = 1;
        *(s32*)(self + 0xE4) = 0;
        *(s32*)(self + 0xDC) = 0x3C;
        self[0xD6] = 0;
        break;
    case 2:
        self[0xD5] = 1;
        *(s32*)(self + 0xE4) = 0x78;
        *(s32*)(self + 0xDC) = 0x96;
        self[0xD6] = 1;
        *(s32*)(self + 0xEC) = 0;
        *(s32*)(self + 0xF0) = 0xF0;
        break;
    case 3:
        self[0xD5] = 1;
        *(s32*)(self + 0xE4) = 0x3C;
        *(s32*)(self + 0xDC) = 0x78;
        self[0xD6] = 0;
        break;
    }
    if (*(s32*)(self + 0xF8) != 0) {
        fn_27_2450E4(*(u8**)(self + 0xF8));
    }
}