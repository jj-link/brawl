#include <types.h>
#pragma force_active on

extern "C" s32 fn_8009C8C0(void* arg0) {
    u8* self = (u8*)arg0;
    u8* ptr;
    s32 type;
    s32 result;
    s32 flag;

    type = *(s32*)(self + 0x40);
    result = 1;
    switch (type) {
    case 0xB:
        ptr = *(u8**)(self + 0x78);
        if (ptr != 0) {
            result = !((ptr[0x11] >> 6) & 1);
        }
        break;
    }
    if (result != 0) {
        if (!((self[0x44] >> 3) & 1)) {
            flag = 0;
        } else {
            switch (type) {
            case 2:
            case 0xC:
                ptr = *(u8**)(self + 0x58);
                if (ptr == 0) {
                    flag = 0;
                } else {
                    flag = (ptr[0x94] >> 4) & 1;
                }
                break;
            default:
                flag = 0;
                break;
            }
        }
        if (flag != 0 && (*(u32*)(self + 0x194) & 7)) {
            result = 0;
        }
    }
    return result;
}
