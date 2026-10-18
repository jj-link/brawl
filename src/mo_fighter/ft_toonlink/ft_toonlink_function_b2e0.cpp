#include <so/work/so_general_work_simple.h>
#pragma force_active on

// ft_toonlink: non-virtual write into the float work array (setFloatWork body).
extern "C" void fn_121_B2E0(soGeneralWorkSimple* work, float value, u32 index) {
    work->m_floatWorks[index] = value;
}
