#include <types.h>
#pragma force_active on

extern "C" int fn_803D5168(unsigned short index);
extern "C" int fn_803D54E0(void* obj, int arg1, unsigned short arg2);
extern "C" int fn_803D60FC(void* buf, int arg1, void* arg2, unsigned short index);

extern "C" int fn_800343CC(void* obj, u64 key, void* c) {
    if (*(s32*)((char*)obj + 0xB4) != 3) {
        return 0;
    }
    int result = 0;
    u32 idx = 0xFFFF;
    u32 i;
    char buf[0x40];

    for (i = 0; i < 0x64; i++) {
        if (fn_803D5168(i) != 0 && fn_803D60FC(buf, 0, 0, i) == 0 &&
            (u64)*(u32*)(buf + 0x2C) == key) {
            idx = i;
            break;
        }
    }
    if ((u16)idx != 0xFFFF && fn_803D54E0(c, 0, idx) == 0) {
        result = 1;
    }
    return result;
}
