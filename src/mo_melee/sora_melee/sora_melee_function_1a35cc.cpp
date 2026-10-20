#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A35CC_obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" void fn_27_1A35CC(fn_27_1A35CC_obj* self) {
    self->unk8 &= ~0x2u;
}
