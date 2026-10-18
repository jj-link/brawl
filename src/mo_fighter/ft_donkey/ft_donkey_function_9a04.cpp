#include <so/work/so_general_work_simple.h>
#pragma force_active on

// Virtual soGeneralWorkSimple::clearFlag: zero the flag word at the given index,
// without the bounds check performed by the non-virtual helper.
extern "C" void fn_92_9A04(soGeneralWorkSimple* work, u32 index) {
    work->m_flagWorks[index] = 0;
}
