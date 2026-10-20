#pragma force_active on
typedef unsigned int u32;

struct FEFD8Obj {
    u32 pad[2];
    u32 hi : 4;
    u32 lo : 28;
};

extern "C" void fn_27_FEFD8(FEFD8Obj* p, u32 v)
{
    p->hi = v;
}
