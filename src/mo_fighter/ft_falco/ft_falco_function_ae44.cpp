#include <types.h>
#pragma force_active on

extern "C" void fn_27_D443C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_108_AE44(void* receiver, s16 id, s32 argument) {
    fn_27_D443C(receiver, id, receiver, (s8)(char)argument);
}
