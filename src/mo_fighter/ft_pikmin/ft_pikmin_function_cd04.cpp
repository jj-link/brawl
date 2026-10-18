#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_113_CD04(soGeneralWorkSimple* work, float value, u32 index) {
    work->m_floatWorks[index] = value;
}
