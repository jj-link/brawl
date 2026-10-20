#include <types.h>
#pragma force_active on

struct fn_27_Elem {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct fn_27_Table {
    u32 header[3];
    fn_27_Elem elems[1];
};

extern "C" void* fn_27_1A24C0(void* base, s32 idx)
{
    return (char*)base + idx * sizeof(fn_27_Elem) + offsetof(fn_27_Table, elems);
}
