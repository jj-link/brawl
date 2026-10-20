#pragma force_active on
typedef unsigned int u32;

struct FnBits {
    u32 pad0;
    u32 pad1;
    u32 unk0 : 3;
    u32 unk1 : 29;
};

extern "C" void fn_27_198490(FnBits *p, u32 v)
{
    p->unk0 = v;
}
