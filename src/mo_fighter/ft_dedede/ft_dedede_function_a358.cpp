#include <ft/fighter.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_D4DF4(void* object, s32 manageId, void* observer, s8 unitId);

extern "C" void fn_117_A358(void* receiver, short id, int argument) {
    fn_27_D4DF4(receiver, id, receiver, argument);
}
