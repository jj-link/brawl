#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FtGwWork {
    char pad[0xc];
    s32* m_values;
};

extern "C" void fn_107_C668(FtGwWork* work, s32 value, u32 index) {
    work->m_values[index] *= value;
}
