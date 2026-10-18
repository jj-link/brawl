#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A7B4C(void* receiver, s32 id, void* owner, s8 argument);

extern "C" void fn_117_A398(void* receiver, s16 id, s32 argument) {
    fn_27_1A7B4C(receiver, id, receiver, static_cast<s8>(argument));
}
