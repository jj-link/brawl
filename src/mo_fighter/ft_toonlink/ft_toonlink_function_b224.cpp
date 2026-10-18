#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_121_B224(soGeneralWorkSimple* work, u32 mask, u32 index) {
    work->m_flagWorks[index] &= ~mask;
}
