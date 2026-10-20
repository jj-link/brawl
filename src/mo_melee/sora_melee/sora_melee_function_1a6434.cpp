#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 hi : 10;
        u32 lo : 22;
    } unk8;
};

extern "C" void fn_27_1A6434(Obj* p, u32 v)
{
    p->unk8.hi = v;
}
