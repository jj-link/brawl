#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8_hi : 6;
    u32 field : 3;
    u32 unk8_lo : 23;
};

extern "C" void fn_27_1CF5F8(Obj* self, u32 v) {
    self->field = v;
}
