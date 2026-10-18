#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" u32 fn_108_B168(const soGeneralWorkSimple* work, u32 mask, u32 index) {
    if (work->m_flagWorks[index] & mask) {
        return 1;
    }
    return 0;
}
