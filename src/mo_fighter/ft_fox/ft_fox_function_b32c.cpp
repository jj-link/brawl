#include <so/work/so_general_work_abstract.h>
#pragma force_active on

// Non-virtual helper shared by Fox's work-table users: it loads the flag
// table pointer directly instead of going through the virtual accessor, then
// zeroes the indexed flag word.
extern "C" void fn_97_B32C(soGeneralWorkAbstract* work, u32 index)
{
    u32* flagWorks = *(u32**)((u8*)work + 0x1c);
    flagWorks[index] = 0;
}
