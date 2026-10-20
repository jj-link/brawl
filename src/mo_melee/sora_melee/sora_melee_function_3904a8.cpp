#pragma force_active on
typedef unsigned int u32;

struct fn_27_3904A8_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_3904A8(fn_27_3904A8_Obj* self) {
    self->flags &= ~0x2000;
}
}
