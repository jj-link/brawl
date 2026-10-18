#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A76C4(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_104_A740(void* receiver, s16 id, int argument) {
    fn_27_1A76C4(receiver, static_cast<s16>(id), receiver, static_cast<s8>(argument));
}
