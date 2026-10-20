#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8_top : 3;
    u32 unk8_rest : 29;
} fn_27_CF9AC_arg;

extern "C" void fn_27_CF9AC(fn_27_CF9AC_arg* p, u32 v)
{
    p->unk8_top = v;
}
