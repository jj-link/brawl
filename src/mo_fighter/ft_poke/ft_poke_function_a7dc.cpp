#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" {
// Returns 1 when any bit in @p mask is set in m_flagWorks[index], else 0.
extern u32 fn_116_A7DC(const soGeneralWorkSimple* work, u32 mask, u32 index)
{
    if (work->m_flagWorks[index] & mask) {
        return 1;
    }
    return 0;
}
}
