#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a;
    u32 b;
    u32 hi : 14;
    u32 field : 7;
    u32 lo : 11;
};

extern "C" void fn_27_D0A20(Bits* self, u32 v) {
    self->field = v;
}
