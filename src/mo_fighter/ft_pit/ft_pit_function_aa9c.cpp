#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct ftPitWork {
    char pad[0xc];
    s32* m_table;
};

extern "C" void fn_112_AA9C(ftPitWork* work, u32 index) {
    work->m_table[index]--;
}
