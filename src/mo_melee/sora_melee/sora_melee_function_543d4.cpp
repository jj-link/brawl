#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 9;
        u32 b : 9;
        u32 c : 14;
    } unk8;
};

extern "C" void fn_27_543D4(Obj *p, u32 v)
{
    p->unk8.b = v;
}
