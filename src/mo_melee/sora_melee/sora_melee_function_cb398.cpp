#pragma force_active on
typedef unsigned int u32;

struct fn_27_CB398_obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_CB398(fn_27_CB398_obj* p) {
    p->flags &= ~0x80u;
}
