#include <types.h>
#pragma force_active on

extern "C" {
s32 fn_8009C864(void* self) {
    s32 var = 0;
    if (*(s32*)((u8*)self + 0x40) == 0xd) {
        void* p = *(void**)((u8*)self + 0x80);
        if (p != 0) {
            s32 t = *(s32*)((u8*)p + 0x8);
            switch (t) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
                var = 1;
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                var = 4;
                break;
            case 9:
                var = 3;
                break;
            }
        }
    }
    return var | 1;
}
}
