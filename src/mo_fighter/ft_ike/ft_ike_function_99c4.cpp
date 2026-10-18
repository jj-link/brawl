#include <so/work/so_general_work_abstract.h>
#include <so/work/so_general_work_simple.h>
#pragma force_active on

// Virtual soGeneralWorkSimple::getFloatWork: fetch a float work slot by index.
// The original loads the float-array pointer (offset 0x14 = m_floatWorks) into
// r3, scales the index by 4 and then issues lfsx with r3 as the base register,
// so the access goes through a local pointer variable to keep that addressing.
extern "C" float fn_119_99C4(const soGeneralWorkSimple* work, u32 index) {
    const float* floatWorks = work->m_floatWorks;
    return floatWorks[index];
}
