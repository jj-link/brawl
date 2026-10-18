#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A7B4C(void*, s32, void*, s8);

extern "C" void fn_98_9D08(void* receiver, s16 id, s8 argument) {
    fn_27_1A7B4C(receiver, id, receiver, argument);
}
