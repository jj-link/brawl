#include <types.h>
#pragma force_active on

extern "C" void fn_27_D512C(void* object, s32 manageId, void* observer, s8 unitId);

extern "C" void fn_117_A344(void* observer, s16 manageId, s32 unitId) {
    fn_27_D512C(observer, manageId, observer, unitId);
}
