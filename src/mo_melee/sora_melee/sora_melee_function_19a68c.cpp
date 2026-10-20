#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 6;
        u32 f : 3;
        u32 b : 23;
    } unk8;
};

extern "C" void fn_27_19A68C(Fn27Obj* p, u32 v)
{
    p->unk8.f = v;
}
