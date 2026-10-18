#include <types.h>
#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_105_DD6C(soGeneralWorkSimple* work, u32 index, float value) {
    work->m_floatWorks[index] = value;
}
