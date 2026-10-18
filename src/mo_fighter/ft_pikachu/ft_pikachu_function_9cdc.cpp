#include <types.h>
#pragma force_active on

extern "C" void fn_27_D443C(void*, s32, void*, s8);

extern "C" void fn_98_9CDC(void* receiver, s16 id, s8 argument) {
    fn_27_D443C(receiver, id, receiver, argument);
}
