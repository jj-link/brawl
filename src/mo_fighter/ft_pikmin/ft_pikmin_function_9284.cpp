#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" const float lbl_113_rodata_C;

static inline void clearInts(soGeneralWorkSimple* work, const s32& count) {
    s32 size = count;
    if ((u32)size >= work->m_intWorkSize)
        size = work->m_intWorkSize;
    for (s32 i = 0; i < size; ++i)
        work->m_intWorks[i] = 0;
}

static inline void clearFloats(soGeneralWorkSimple* work, const s32& count) {
    s32 size = count;
    if ((u32)size >= work->m_floatWorkSize)
        size = work->m_floatWorkSize;
    for (s32 i = 0; i < size; ++i)
        work->m_floatWorks[i] = lbl_113_rodata_C;
}

static inline void clearFlags(soGeneralWorkSimple* work, const s32& count) {
    s32 size = count;
    if ((u32)size >= work->m_flagWorkSize)
        size = work->m_flagWorkSize;
    for (s32 i = 0; i < size; ++i)
        work->m_flagWorks[i] = 0;
}

extern "C" void fn_113_9284(soGeneralWorkSimple* work) {
    clearInts(work, reinterpret_cast<const s32&>(work->m_intWorkSize));
    clearFloats(work, reinterpret_cast<const s32&>(work->m_floatWorkSize));
    clearFlags(work, reinterpret_cast<const s32&>(work->m_flagWorkSize));
}
