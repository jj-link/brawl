#include <types.h>
#pragma force_active on

extern "C" void fn_27_D46B8(void* receiver, s16 manageId, void* observer, s8 unitId);

extern "C" void fn_115_9EF8(void* observer, s16 manageId, s32 unitId) {
    fn_27_D46B8(observer, manageId, observer, static_cast<s8>(unitId));
}
