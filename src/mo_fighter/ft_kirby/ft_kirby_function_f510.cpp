#include <so/work/so_general_work_simple.h>
#pragma force_active on

// Getter callback for the float work table: reads m_floatWorks (offset 0x14)
// at the requested index.  Identical to soGeneralWorkSimple::getFloatWork.
extern "C" float fn_96_F510(const soGeneralWorkSimple* work, u32 index) {
    return work->m_floatWorks[index];
}
