#include <so/work/so_general_work_simple.h>
#pragma force_active on

// Direct (non-virtual) write into the int work storage:
// loads the int-work pointer (m_intWorks at offset 0xC) and stores value at
// the given index, with no bounds check.
extern "C" void fn_102_92F0(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->m_intWorks[index] = value;
}
