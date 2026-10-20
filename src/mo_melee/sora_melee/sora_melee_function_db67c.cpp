#include <types.h>
#pragma force_active on

typedef struct {
    u32 pad0;
    u32 unk4;
    u32 flags;
} fn_27_DB67C_obj;

extern "C" s32 fn_27_DB67C(fn_27_DB67C_obj* p) {
    return (s32)(((p->flags >> 22) & 0xF) << 28) >> 29;
}
