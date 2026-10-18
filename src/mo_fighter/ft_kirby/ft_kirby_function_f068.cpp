#include <types.h>
#pragma force_active on

extern "C" void fn_27_D48FC(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_96_F068(void* receiver, s16 id, int argument) {
    fn_27_D48FC(receiver, id, receiver, static_cast<s8>(argument));
}
