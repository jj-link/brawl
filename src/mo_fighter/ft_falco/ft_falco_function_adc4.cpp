#include <types.h>
#pragma force_active on

extern "C" void fn_27_D4B78(void* receiver, s32 manageId, void* observer, s32 unitId);

extern "C" void fn_108_ADC4(void* observer, s16 manageId, s8 unitId)
{
    fn_27_D4B78(observer, (s32)manageId, observer, (s32)unitId);
}
