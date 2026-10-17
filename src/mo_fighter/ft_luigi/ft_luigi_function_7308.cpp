#include <so/work/so_general_work_simple.h>

extern "C" const float lbl_99_rodata_8;

extern "C" void fn_99_7308(soGeneralWorkSimple* work) {
    s32 intWorkSize = work->m_intWorkSize;
    intWorkSize = (intWorkSize != work->m_intWorkSize) ? work->m_intWorkSize : intWorkSize;
    for (s32 i = 0; i < intWorkSize; i++) {
        work->m_intWorks[i] = 0;
    }

    s32 floatWorkSize = work->m_floatWorkSize;
    floatWorkSize = (floatWorkSize != work->m_floatWorkSize) ? work->m_floatWorkSize : floatWorkSize;
    for (s32 i = 0; i < floatWorkSize; i++) {
        work->m_floatWorks[i] = lbl_99_rodata_8;
    }

    s32 flagWorkSize = work->m_flagWorkSize;
    flagWorkSize = (flagWorkSize != work->m_flagWorkSize) ? work->m_flagWorkSize : flagWorkSize;
    for (s32 i = 0; i < flagWorkSize; i++) {
        work->m_flagWorks[i] = 0;
    }
}
