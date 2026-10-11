#include <types.h>

extern "C" void fn_27_D3E88(void*, s32, void*, s8);
extern "C" void fn_27_D46B8(void*, s32, void*, s8);
extern "C" void fn_27_D4B78(void*, s32, void*, s8);

extern "C" void fn_98_9C34(void* observer, s16 manageId, s8 priority) {
    fn_27_D3E88(observer, manageId, observer, priority);
}

extern "C" void fn_98_9C48(void* observer, s16 manageId, s8 priority) {
    fn_27_D46B8(observer, manageId, observer, priority);
}

extern "C" void fn_98_9C5C(void* observer, s16 manageId, s8 priority) {
    fn_27_D4B78(observer, manageId, observer, priority);
}
