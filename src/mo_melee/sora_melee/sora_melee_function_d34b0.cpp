#pragma force_active on
typedef unsigned int u32;

struct fn_27_D34B0_obj {
    u32 unk0;
    u32 unk4;
    u32 flags : 3;
};

extern "C" void fn_27_D34B0(fn_27_D34B0_obj *p, u32 v) {
    p->flags = v;
}
