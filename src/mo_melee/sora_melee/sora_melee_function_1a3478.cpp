#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[8];
    u32 hi : 10;
    u32 lo : 22;
};

extern "C" {
void fn_27_1A3478(Obj* p, u32 v)
{
    p->hi = v;
}
}
