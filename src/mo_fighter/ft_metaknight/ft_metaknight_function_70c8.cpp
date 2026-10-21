#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" const float lbl_111_rodata_8;

extern "C" void fn_111_70C8(soGeneralWorkSimple* work) {
    s32 i;
    s32 intWorkSize = ((const u32*)work)[4];
    if (intWorkSize >= work->m_intWorkSize) {
        intWorkSize = work->m_intWorkSize;
    }
    for (i = 0; i < intWorkSize; i++) {
        work->m_intWorks[i] = 0;
    }

    s32 j;
    s32 floatWorkSize = ((const u32*)work)[6];
    if (floatWorkSize >= work->m_floatWorkSize) {
        floatWorkSize = work->m_floatWorkSize;
    }
    for (j = 0; j < floatWorkSize; j++) {
        work->m_floatWorks[j] = lbl_111_rodata_8;
    }

    s32 k;
    s32 flagWorkSize = ((const u32*)work)[8];
    if (flagWorkSize >= work->m_flagWorkSize) {
        flagWorkSize = work->m_flagWorkSize;
    }
    for (k = 0; k < flagWorkSize; k++) {
        work->m_flagWorks[k] = 0;
    }
}
