#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 high : 10;
    u32 field : 10;
    u32 low : 12;
};

extern "C" {
void fn_27_1A6558(Obj* p, u32 v)
{
    p->field = v;
}
}
