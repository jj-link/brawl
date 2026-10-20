#pragma force_active on
typedef unsigned int u32;

struct fn_27_D169C_obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_D169C(fn_27_D169C_obj* p) {
    p->flags |= 0x80;
}
