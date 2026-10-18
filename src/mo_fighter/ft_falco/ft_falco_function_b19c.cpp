#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_108_B19C(soGeneralWorkSimple* work, u32 index) {
    work->soGeneralWorkSimple::clearFlag(index);
}
