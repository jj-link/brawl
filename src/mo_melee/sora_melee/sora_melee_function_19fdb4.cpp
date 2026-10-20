#pragma force_active on
typedef unsigned int u32;

struct fn_27_19FDB4_Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 6;
    u32 f : 3;
    u32 lo : 23;
};

extern "C" void fn_27_19FDB4(fn_27_19FDB4_Obj* p, u32 v)
{
    p->f = v;
}
