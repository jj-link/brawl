#include <so/work/so_general_work_simple.h>
#pragma force_active on

// Non-virtual write into the float work array: load m_floatWorks (offset 0x14)
// and store the float argument at [pointer + 4*index], as in setFloatWork's body.
extern "C" void fn_93_B2E4(soGeneralWorkSimple* work, float value, u32 index) {
    work->m_floatWorks[index] = value;
}
