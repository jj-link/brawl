#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" float fn_105_DD7C(const soGeneralWorkSimple* work, u32 index) {
    return work->m_floatWorks[index];
}
