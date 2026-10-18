#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_105_DE2C(soGeneralWorkSimple* work, s32 value, u32 index)
{
    work->soGeneralWorkSimple::setIntWork(value, index);
}
