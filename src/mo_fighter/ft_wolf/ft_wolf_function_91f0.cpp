#include <so/work/so_general_work_simple.h>
#pragma force_active on
extern "C" const float lbl_125_rodata_8;
#pragma optimization_level 1
extern "C" void fn_125_91F0(soGeneralWorkSimple* work) {
    s32 intIndex;
    s32 intWorkSize = work->m_intWorkSize;
    u32 intLimit = work->m_intWorkSize;
    if ((u32)intWorkSize >= intLimit) intWorkSize = intLimit;
    for (intIndex = 0; intIndex < intWorkSize; intIndex++) {
        work->m_intWorks[intIndex] = 0;
    }
    s32 floatIndex;
    s32 floatWorkSize = work->m_floatWorkSize;
    u32 floatLimit = work->m_floatWorkSize;
    if ((u32)floatWorkSize >= floatLimit) floatWorkSize = floatLimit;
    for (floatIndex = 0; floatIndex < floatWorkSize; floatIndex++) {
        work->m_floatWorks[floatIndex] = lbl_125_rodata_8;
    }
    s32 flagIndex;
    s32 flagWorkSize = work->m_flagWorkSize;
    u32 flagLimit = work->m_flagWorkSize;
    if ((u32)flagWorkSize >= flagLimit) flagWorkSize = flagLimit;
    for (flagIndex = 0; flagIndex < flagWorkSize; flagIndex++) {
        work->m_flagWorks[flagIndex] = 0;
    }
}