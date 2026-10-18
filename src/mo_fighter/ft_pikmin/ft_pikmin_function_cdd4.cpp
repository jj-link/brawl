#include <so/work/so_general_work_simple.h>
#pragma force_active on

// Inlined non-virtual call: r3 = work->m_intWorks (0xC), then lwzx r3, r3, index*4
extern "C" s32 fn_113_CDD4(soGeneralWorkSimple* work, u32 index) {
    return work->soGeneralWorkSimple::getIntWork(index);
}
