#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 w0;
    u32 w1;
    u32 field : 7;
};

extern "C" void fn_27_D01A4(Obj* p, u32 v)
{
    p->field = v;
}
