#include <types.h>
#pragma force_active on

extern "C" void fn_27_D48FC(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_116_A45C(void* receiver, s16 id, int argument) {
    fn_27_D48FC(receiver, static_cast<s16>(id), receiver, static_cast<s8>(argument));
}
