#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A5700_bits {
    u32 hi : 4;
    u32 lo : 28;
};

struct fn_27_1A5700_obj {
    u32 unk0;
    u32 unk4;
    fn_27_1A5700_bits unk8;
};

extern "C" {
void fn_27_1A5700(fn_27_1A5700_obj* self, u32 v) {
    self->unk8.hi = v;
}
}
