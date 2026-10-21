#include <so/work/so_general_work_simple.h>
#pragma force_active on

static inline u32 minimum(const u32& a, const u32& b) {
    return a >= b ? b : a;
}

extern "C" const float lbl_121_rodata_C;

extern "C" void fn_121_48C8(soGeneralWorkSimple* work) {
    {
    s32 i;
    u32 intWorkSize = work->m_intWorkSize;
    intWorkSize = minimum(intWorkSize, work->m_intWorkSize);
    for (i = 0; i < (s32)intWorkSize; i++) {
        work->m_intWorks[i] = 0;
    }
    }

    {
    s32 i;
    u32 floatWorkSize = work->m_floatWorkSize;
    floatWorkSize = minimum(floatWorkSize, work->m_floatWorkSize);
    for (i = 0; i < (s32)floatWorkSize; i++) {
        work->m_floatWorks[i] = lbl_121_rodata_C;
    }
    }

    {
    s32 i;
    u32 flagWorkSize = work->m_flagWorkSize;
    flagWorkSize = minimum(flagWorkSize, work->m_flagWorkSize);
    for (i = 0; i < (s32)flagWorkSize; i++) {
        work->m_flagWorks[i] = 0;
    }
    }
}