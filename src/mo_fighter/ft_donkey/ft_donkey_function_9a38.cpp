#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" const float lbl_92_rodata_8;

extern "C" void fn_92_9A38(soGeneralWorkSimple* work, u32 index, float value) {
    if (lbl_92_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}
