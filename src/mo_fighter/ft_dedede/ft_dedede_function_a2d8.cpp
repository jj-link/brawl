#include <types.h>
#pragma force_active on

extern "C" void fn_27_D46B8(void* observer, s16 manageId, void* owner,  s8 unitId);

extern "C" void fn_117_A2D8(void* observer, s16 manageId, int unitId) {
     s8 arg = static_cast<s8>(unitId);
    fn_27_D46B8(observer, manageId, observer, arg);
}
