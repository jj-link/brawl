#pragma force_active on
typedef unsigned int u32;

struct FlagWorkHolder {
    char pad[0x1c];
    u32 *m_bits;
};

extern "C" void fn_96_F470(FlagWorkHolder *work, u32 mask, u32 index) {
    work->m_bits[index] |= mask;
}
