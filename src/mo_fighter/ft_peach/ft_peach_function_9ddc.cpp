#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_D512C(void* object, s32 manageId, void* observer, s8 unitId);

void fn_103_9DDC(void* object, s16 id, s32 unit) {
    fn_27_D512C(object, id, object, (s8)unit);
}
}
