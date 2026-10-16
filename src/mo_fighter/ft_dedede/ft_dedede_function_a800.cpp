// fn_117_A800 is the direct (non-virtual) form of
// soGeneralWorkSimple::divIntWork(s32 value, u32 index): the original words at
// .text[0xA800,0xA820) are 2c040000 4d820020 80c3000c 54a3103a 7c06182e
// 7c0023d6 7c06192e 4e800020 = cmpwi r4,0; beqlr; lwz r6,12(r3); slwi r3,r5,2;
// lwzx r0,r6,r3; divw r0,r0,r4; stwx r0,r6,r3; blr, i.e. guard a zero divisor
// and divide m_intWorks[index] (the s32* member at offset 0xC) by value in
// place, with no vtable dispatch (r3=work, r4=value, r5=index).
//
// The body is spelled exactly as the class's virtual divIntWork
// (include/lib/BrawlHeaders/Brawl/Include/so/work/so_general_work_simple.h:
// "if (0 != value) { m_intWorks[index] /= value; }"). Sibling slots confirm
// the family: A7D0/A7E8 are the direct decIntWork/incIntWork bodies
// (addi -1/+1) and A820 is the direct mulIntWork body (mullw, no guard), all
// loading m_intWorks with lwz r6,12(r3) and scaling the index with
// slwi rX,rY,2.
#include <so/work/so_general_work_simple.h>

extern "C" void fn_117_A800(soGeneralWorkSimple* work, s32 value, u32 index) {
    if (0 != value) {
        work->m_intWorks[index] /= value;
    }
}
