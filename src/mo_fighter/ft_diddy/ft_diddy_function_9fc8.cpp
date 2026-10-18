#include <types.h>
#pragma force_active on

extern "C" void fn_27_D3C0C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_115_9FC8(void* receiver, s16 id, int argument) {
    fn_27_D3C0C(receiver, static_cast<s16>(id), receiver, static_cast<s8>(argument));
}
