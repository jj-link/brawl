#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Work {
    unsigned char pad[12];
    s32* m_intWorks;
    u32 m_intWorkSize;
    float* m_floatWorks;
    u32 m_floatWorkSize;
    u32* m_flagWorks;
    u32 m_flagWorkSize;
};

extern "C" const float lbl_122_rodata_C;

inline void clearInts(Work* work, const u32& count) {
    s32 n = count;
    if (n >= work->m_intWorkSize)
        n = work->m_intWorkSize;
    for (s32 i = 0; i < n; ++i)
        work->m_intWorks[i] = 0;
}

inline void clearFloats(Work* work, const u32& count) {
    s32 n = count;
    if (n >= work->m_floatWorkSize)
        n = work->m_floatWorkSize;
    for (s32 i = 0; i < n; ++i)
        work->m_floatWorks[i] = lbl_122_rodata_C;
}

inline void clearFlags(Work* work, const u32& count) {
    s32 n = count;
    if (n >= work->m_flagWorkSize)
        n = work->m_flagWorkSize;
    for (s32 i = 0; i < n; ++i)
        work->m_flagWorks[i] = 0;
}

extern "C" void fn_122_BDE0(Work* work) {
    clearInts(work, work->m_intWorkSize);
    clearFloats(work, work->m_floatWorkSize);
    clearFlags(work, work->m_flagWorkSize);
}
