#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_94_B048(soGeneralWorkSimple* work, s32 value, u32 index) {
    if (0 != value) {
        work->m_intWorks[index] /= value;
    }
}
