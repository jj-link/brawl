#include <types.h>
#pragma force_active on

extern "C" void fn_27_D512C(void* object, s16 manageId, void* observer, s8 unitId);

extern "C" void fn_119_95F0(void* receiver, s16 id, s32 argument) {
    fn_27_D512C(receiver, id, receiver, (s8)argument);
}
