#pragma force_active on
typedef unsigned int u32;

struct FtWork {
    char pad[0xc];
    u32* m_values;
};

extern "C" void fn_126_7674(FtWork* work, u32 value, u32 index) {
    work->m_values[index] += value;
}
