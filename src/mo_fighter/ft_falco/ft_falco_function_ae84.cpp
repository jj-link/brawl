#include <types.h>
#pragma force_active on

extern "C" void fn_27_D3C0C(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_108_AE84(void* receiver, s16 argument, int argument2) {
    fn_27_D3C0C(receiver, argument, receiver, static_cast<s8>(argument2));
}
