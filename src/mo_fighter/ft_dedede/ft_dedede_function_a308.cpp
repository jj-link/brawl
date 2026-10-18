#include <types.h>
#pragma force_active on

extern "C" void fn_27_D48FC(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_117_A308(void* receiver, s16 id, s32 argument) {
    fn_27_D48FC(receiver, id, receiver, static_cast<s8>(argument));
}
