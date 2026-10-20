#pragma force_active on
typedef unsigned int u32;

struct fn_27_1E7C10_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1E7C10(fn_27_1E7C10_Obj* self) {
    self->flags &= ~0x02000000;
}
