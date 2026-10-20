#pragma force_active on
typedef unsigned int u32;

struct Obj198EC4 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" void fn_27_198EC4(Obj198EC4 *p)
{
    p->unk8 &= 0xFDFFFFFF;
}
