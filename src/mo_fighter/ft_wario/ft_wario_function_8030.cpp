#pragma optimization_level 1
#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" const float lbl_110_rodata_8;

extern "C" void fn_110_8030(soGeneralWorkSimple* work) {
    s32 i;
    u32 intWorkSize = work->m_intWorkSize;
    u32 intLimit = work->m_intWorkSize;
    if (intWorkSize >= intLimit) intWorkSize = intLimit;
    for (i = 0; i < (s32)intWorkSize; i++) {
        work->m_intWorks[i] = 0;
    }

    s32 j;
    u32 floatWorkSize = work->m_floatWorkSize;
    u32 floatLimit = work->m_floatWorkSize;
    if (floatWorkSize >= floatLimit) floatWorkSize = floatLimit;
    for (j = 0; j < (s32)floatWorkSize; j++) {
        work->m_floatWorks[j] = lbl_110_rodata_8;
    }

    s32 k;
    u32 flagWorkSize = work->m_flagWorkSize;
    u32 flagLimit = work->m_flagWorkSize;
    if (flagWorkSize >= flagLimit) flagWorkSize = flagLimit;
    for (k = 0; k < (s32)flagWorkSize; k++) {
        work->m_flagWorks[k] = 0;
    }
}
