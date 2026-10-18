#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_115_A3C4(soGeneralWorkSimple* work, float value, u32 index) {
    work->m_floatWorks[index] = value;
}
