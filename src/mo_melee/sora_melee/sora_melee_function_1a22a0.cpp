#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 w0;
    u32 w1;
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" {
void fn_27_1A22A0(Obj* p, u32 v)
{
    p->b = v;
}
}
