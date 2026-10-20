#pragma force_active on
typedef unsigned int u32;

struct fn_27_1D0B3C_obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_1D0B3C(fn_27_1D0B3C_obj* self) {
    self->flags &= ~0x00080000;
}
}
