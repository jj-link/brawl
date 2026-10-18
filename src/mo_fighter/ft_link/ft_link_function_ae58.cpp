#include <types.h>
#pragma force_active on

extern "C" void fn_27_D46B8(void* receiver, s16 id, void* owner, s8 argument);

extern "C" void fn_93_AE58(void* object, s16 id, s8 unit) {
    fn_27_D46B8(object, id, object, unit);
}
