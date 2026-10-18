#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtGwWork {
    char pad[0xc];
    s32* m_counts;
};

extern "C" void fn_107_C630(FtGwWork* work, u32 index) {
    work->m_counts[index]++;
}
