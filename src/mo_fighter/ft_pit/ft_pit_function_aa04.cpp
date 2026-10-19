#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" const float lbl_112_rodata_8;

extern "C" void fn_112_AA04(soGeneralWorkSimple* work, float value, u32 index) {
    if (lbl_112_rodata_8 != value) {
        work->m_floatWorks[index] /= value;
    }
}
