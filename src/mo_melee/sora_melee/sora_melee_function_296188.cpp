#pragma force_active on
typedef unsigned int u32;

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 6;
        u32 b : 6;
        u32 c : 20;
    } unk8;
};

extern "C" {
void fn_27_296188(fn27Obj* p, u32 v)
{
    p->unk8.b = v;
}
}
