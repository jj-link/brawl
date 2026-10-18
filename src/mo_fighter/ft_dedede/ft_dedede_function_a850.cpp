#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_117_A850(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->m_intWorks[index] += value;
}
