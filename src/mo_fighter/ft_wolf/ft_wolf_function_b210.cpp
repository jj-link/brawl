#pragma force_active on
struct Work {
    char pad[0x1c];
    unsigned int* m_flags;
};

extern "C" bool fn_125_B210(const Work* work, unsigned int mask, int index) {
    return (work->m_flags[index] & mask) != 0;
}
