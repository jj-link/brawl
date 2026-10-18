#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" u32 fn_92_99D0(const soGeneralWorkSimple* work, u32 flag, u32 index) {
    return (work->m_flagWorks[index] & flag) != 0;
}
