#pragma force_active on
typedef unsigned int u32;

struct FtWork {
    char pad[0x1c];
    u32* m_array;
};

extern "C" void fn_96_F45C(FtWork* work, u32 index) {
    work->m_array[index] = 0;
}
