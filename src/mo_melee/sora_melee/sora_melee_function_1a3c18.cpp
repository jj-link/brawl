#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 20;
        u32 b : 10;
        u32 c : 2;
    } flags;
} Obj;

extern "C" void fn_27_1A3C18(Obj* p, u32 v)
{
    p->flags.b = v;
}
