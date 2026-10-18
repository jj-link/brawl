#include <types.h>
#pragma force_active on

extern "C" void fn_27_D4DF4(void* object, s16 manageId, void* observer, s8 unitId);

extern "C" void fn_98_9CC8(void* receiver, s16 id, s8 argument) {
    fn_27_D4DF4(receiver, id, receiver, argument);
}
