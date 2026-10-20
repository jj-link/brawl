#include <types.h>
#pragma force_active on

struct fn_27_19B540_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_19B540(fn_27_19B540_arg* p) {
    u32 x = p->unk8;
    return ((s32)(((x << 6) | (x >> 26)) & 0xFE000000u)) >> 26;
}
