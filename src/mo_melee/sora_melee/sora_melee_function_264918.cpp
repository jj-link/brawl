#include <types.h>
#pragma force_active on

// Reads a 2-bit signed field (bits 4-5) from the word stored at offset 8.
struct fn_27_264918_struct {
    u32 unk0;
    u32 unk4;
    u32 c : 4;
    s32 d : 2;
    u32 e : 26;
};

extern "C" s32 fn_27_264918(fn_27_264918_struct* p) {
    return p->d;
}
