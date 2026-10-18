#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_110_9920(soGeneralWorkSimple* work, float value, u32 index) {
    work->soGeneralWorkSimple::setFloatWork(value, index);
}
