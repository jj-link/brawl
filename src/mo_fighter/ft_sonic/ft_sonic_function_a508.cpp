// fn_123_A508 is the direct (non-virtual) form of
// soGeneralWorkSimple::divIntWork(s32 value, u32 index): guard a zero divisor
// and divide m_intWorks[index] (the s32* member at offset 0xC) by value in
// place, with no vtable dispatch (r3=work, r4=value, r5=index).
//
// The body is spelled exactly as the class's virtual divIntWork
// (include/lib/BrawlHeaders/Brawl/Include/so/work/so_general_work_simple.h:
// "if (0 != value) { m_intWorks[index] /= value; }").
#include <so/work/so_general_work_simple.h>
#pragma force_active on

extern "C" void fn_123_A508(soGeneralWorkSimple* work, s32 value, u32 index) {
    if (0 != value) {
        work->m_intWorks[index] /= value;
    }
}
