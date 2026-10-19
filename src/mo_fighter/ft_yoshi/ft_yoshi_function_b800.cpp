#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" bool fn_95_B800(const soGeneralWorkSimple* work, u32 mask, u32 index) {
    return work->m_flagWorks[index] & mask;
}
