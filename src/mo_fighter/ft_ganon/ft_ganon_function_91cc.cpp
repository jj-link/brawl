#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" bool fn_109_91CC(const soGeneralWorkSimple* work, u32 flag, u32 index) {
    return work->m_flagWorks[index] & flag;
}
