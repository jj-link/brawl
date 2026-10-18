#include <so/work/so_general_work_simple.h>
#pragma force_active on

// ft_wolf: write a float work entry (equivalent of the virtual setFloatWork).
extern "C" void fn_125_B2E8(soGeneralWorkSimple* work, u32 index, float value) {
    work->m_floatWorks[index] = value;
}
