#include <types.h>
#pragma force_active on

struct Sub {
    u8 pad[8];
    s8 f8;
};

struct Obj {
    u16* f0;
    Sub* f4;
};

extern "C" s32 fn_801B6A80(Obj* arg0, s32 arg1) {
    u16* p = arg0->f0;
    s32 flag = 0;
    if (p != 0 && arg0->f4 != 0) {
        flag = 1;
    }
    if (flag != 0) {
        if (arg1 < 0) {
            arg0->f4->f8 = -1;
            return 1;
        }
        if (arg1 < (s32)*p) {
            arg0->f4->f8 = (s8)arg1;
            return 1;
        }
    }
    return 0;
}
