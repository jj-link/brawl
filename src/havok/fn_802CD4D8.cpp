#pragma force_active on
typedef unsigned int u32;

struct S {
    char pad[0x1c];
    u32 bits[16];
};

extern "C" void fn_802CD4D8(S* f, int arg1, int arg2) {
    f->bits[arg1] &= ~(1 << arg2);
    f->bits[arg2] &= ~(1 << arg1);
}
