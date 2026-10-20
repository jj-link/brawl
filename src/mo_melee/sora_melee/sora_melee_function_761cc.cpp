#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8 : 5;
    u32 unk8_rest : 27;
} FooObj;

extern "C" void fn_27_761CC(FooObj* p, u32 v)
{
    p->unk8 = v;
}
