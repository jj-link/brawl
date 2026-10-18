#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A7B4C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_115_9FB4(void* observer, s16 manageId, s8 unitId) {
    fn_27_1A7B4C(observer, manageId, observer, unitId);
}
