#include <so/work/so_general_work_simple.h>
#pragma force_active on

// Original semantics: read the float-work pointer (offset 0x14 = m_floatWorks)
// and store the float argument (f1) at [pointer + 4*index] — i.e. a direct
// non-virtual write into the float work array, as in setFloatWork's body.
extern "C" void fn_102_9230(soGeneralWorkSimple* work, float value, u32 index) {
    work->m_floatWorks[index] = value;
}