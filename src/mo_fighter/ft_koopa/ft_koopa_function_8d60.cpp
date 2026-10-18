#include <types.h>
#pragma force_active on

extern "C" void fn_27_D38D4(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_102_8D60(void* receiver, s16 id, int argument) {
    fn_27_D38D4(receiver, id, receiver, static_cast<s8>(argument));
}
