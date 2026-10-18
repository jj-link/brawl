#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct FtPokeWork {
    u8 pad[0xC];
    u32 *m_counts;
};

extern "C" void fn_116_A8F4(FtPokeWork *work, u32 index) {
    work->m_counts[index] += 1;
}
