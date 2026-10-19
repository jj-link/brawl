#include <so/work/so_general_work_simple.h>
#include <types.h>
#pragma force_active on

extern "C" u32 fn_120_99FC(const soGeneralWorkSimple* work, u32 flag, u32 index) {
    return (work->m_flagWorks[index] & flag) != 0;
}
