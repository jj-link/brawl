#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} FnObj;

extern "C" void fn_27_1CFCCC(FnObj* p)
{
    p->unk8 |= 0x10000;
}
