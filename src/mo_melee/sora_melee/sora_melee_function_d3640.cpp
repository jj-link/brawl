#pragma force_active on
typedef unsigned int u32;

struct fn_27_D3640_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" void fn_27_D3640(fn_27_D3640_Obj* p)
{
    p->unk8 &= ~0x00010000;
}
