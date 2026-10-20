#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 mode : 3;
} fn27Obj;

extern "C" void fn_27_198FE8(fn27Obj* obj, u32 mode)
{
    obj->mode = mode;
}
