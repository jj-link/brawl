#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

extern "C" void fn_27_D29FC(Obj* p, u32 v)
{
    p->b = v;
}
