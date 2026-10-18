#pragma force_active on
typedef unsigned int u32;

struct Obj {
    char pad[0x18];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
};

extern "C" void fn_27_362C(Obj* p)
{
    p->f18 = 0;
    p->f20 = 0;
    p->f1c = 0;
    p->f24 = 0;
}
