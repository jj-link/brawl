#include <types.h>

extern "C" void fn_27_D3E88(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_D46B8(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_D4B78(void* object, s32 manageId, void* observer, s8 unitId);

extern "C" void fn_111_8470(void*) {
}

extern "C" u8 fn_111_8474(const void* object) {
    return static_cast<const u8*>(object)[0x44];
}

extern "C" void fn_111_847C(void*) {
}

extern "C" void fn_111_8480(void* observer, s16 manageId, s8 unitId) {
    fn_27_D3E88(observer, manageId, observer, unitId);
}

extern "C" void fn_111_8494(void* observer, s16 manageId, s8 unitId) {
    fn_27_D46B8(observer, manageId, observer, unitId);
}

extern "C" void fn_111_84A8(void* observer, s16 manageId, s8 unitId) {
    fn_27_D4B78(observer, manageId, observer, unitId);
}
