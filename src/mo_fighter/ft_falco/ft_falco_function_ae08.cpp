#include <types.h>
#pragma force_active on

extern "C" void fn_27_D5464(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_108_AE08(void* owner, s16 id, s8 argument) {
    fn_27_D5464(owner, id, owner, argument);
}
