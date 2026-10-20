#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 m0;
    u32 m4;
    u32 m8;
};

extern "C" u32 fn_27_1A33D4(const Flags* flags) {
    return (flags->m8 >> 1) & 1;
}
