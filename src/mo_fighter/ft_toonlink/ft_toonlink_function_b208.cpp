#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" bool fn_121_B208(const soGeneralWorkSimple* work, u32 flag, u32 index) {
    return (work->m_flagWorks[index] & flag) != 0;
}
