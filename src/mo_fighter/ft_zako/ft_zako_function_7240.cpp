#include <types.h>
#pragma force_active on

extern "C" void fn_27_1A76C4(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_126_7240(void* receiver, s16 id, s8 argument) {
    fn_27_1A76C4(receiver, id, receiver, argument);
}
