#include <types.h>
#pragma force_active on

typedef struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
} fn27Obj;

extern "C" void fn_27_19E694(fn27Obj* p) {
    p->flags |= 0x2000;
}
