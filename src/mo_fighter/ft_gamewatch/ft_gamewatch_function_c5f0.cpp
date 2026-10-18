#include <so/work/so_general_work_simple.h>
#pragma force_active on

// ft_gamewatch: write a float work entry (equivalent of the virtual setFloatWork).
extern "C" void fn_107_C5F0(soGeneralWorkSimple* work, u32 index, float value) {
    work->m_floatWorks[index] = value;
}
