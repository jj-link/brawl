#pragma force_active on
typedef unsigned int u32;

struct WorkBuf {
    u32 m_pad[3];
    u32* m_works;
};

extern "C" void fn_110_99C8(WorkBuf* work, u32 value, u32 index) {
    work->m_works[index] += value;
}
