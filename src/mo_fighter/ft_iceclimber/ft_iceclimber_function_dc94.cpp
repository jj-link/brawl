#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" u32 fn_105_DC94(const soGeneralWorkSimple* work, u32 mask, u32 index) {
    return (mask & work->m_flagWorks[index]) != 0;
}
