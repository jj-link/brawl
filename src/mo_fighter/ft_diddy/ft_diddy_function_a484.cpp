#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_115_A484(soGeneralWorkSimple* work, s32 value, u32 index) {
    work->soGeneralWorkSimple::setIntWork(value, index);
}
