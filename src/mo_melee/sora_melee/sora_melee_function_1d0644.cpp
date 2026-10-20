#include <types.h>
#pragma force_active on

struct obj_t {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" u32 fn_27_1D0644(const obj_t* p) {
    return (p->unk8 << 6) >> 31;
}