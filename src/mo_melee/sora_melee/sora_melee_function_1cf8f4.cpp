#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 w0;
    u32 w1;
    u32 hi : 6;
    u32 lo : 26;
};

extern "C" void fn_27_1CF8F4(Flags* self, u32 value) {
    self->hi = value;
}
