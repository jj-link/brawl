#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Flags {
    u32 a : 4;
    u32 b : 2;
    u32 c : 26;
};

extern "C" void fn_27_CC1E8(u8* self, u32 v) {
    Flags* f = (Flags*)(self + 8);
    f->b = v;
}
