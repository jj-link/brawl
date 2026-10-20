#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 field : 4;
    u32 rest : 28;
} fn_27_199468_t;

extern "C" void fn_27_199468(fn_27_199468_t* p, u32 v)
{
    p->field = v;
}
