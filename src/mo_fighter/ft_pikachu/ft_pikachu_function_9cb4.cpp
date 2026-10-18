#include <types.h>
#pragma force_active on

extern "C" void fn_27_D512C(void*, s32, void*, s8);

extern "C" void fn_98_9CB4(void* observer, s16 manageId, s8 priority) {
    fn_27_D512C(observer, manageId, observer, priority);
}
