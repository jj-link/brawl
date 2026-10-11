#include <ft/fighter.h>
#include <types.h>

extern "C" void fn_27_D48FC(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_1A8258(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_D5464(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_D512C(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_D4DF4(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_D443C(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_1A8014(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_1A7B4C(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_D3C0C(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_1A7908(void* object, s32 manageId, void* observer, s8 unitId);
extern "C" void fn_27_1A76C4(void* object, s32 manageId, void* observer, s8 unitId);

// These observer callbacks are genuinely empty in the original module.
extern "C" void fn_111_84BC(void*) {}
extern "C" void fn_111_84C0(void*) {}

extern "C" void fn_111_84C4(void* observer, s16 manageId, s8 unitId) {
    fn_27_D48FC(observer, manageId, observer, unitId);
}

extern "C" void fn_111_84D8(void* observer, s16 manageId, s8 unitId) {
    fn_27_1A8258(observer, manageId, observer, unitId);
}

extern "C" void fn_111_84EC(void* observer, s16 manageId, s8 unitId) {
    fn_27_D5464(observer, manageId, observer, unitId);
}

extern "C" void fn_111_8500(void* observer, s16 manageId, s8 unitId) {
    fn_27_D512C(observer, manageId, observer, unitId);
}

extern "C" void fn_111_8514(void* observer, s16 manageId, s8 unitId) {
    fn_27_D4DF4(observer, manageId, observer, unitId);
}

extern "C" void fn_111_8528(void* observer, s16 manageId, s8 unitId) {
    fn_27_D443C(observer, manageId, observer, unitId);
}

extern "C" void fn_111_853C(void* observer, s16 manageId, s8 unitId) {
    fn_27_1A8014(observer, manageId, observer, unitId);
}

extern "C" void fn_111_8550(void* observer, s16 manageId, s8 unitId) {
    fn_27_1A7B4C(observer, manageId, observer, unitId);
}

extern "C" void fn_111_8564(void* observer, s16 manageId, s8 unitId) {
    fn_27_D3C0C(observer, manageId, observer, unitId);
}

extern "C" void fn_111_8578(void*) {}
extern "C" void fn_111_857C(void*) {}
extern "C" void fn_111_8580(void*) {}
extern "C" void fn_111_8584(void*) {}
extern "C" void fn_111_8588(void*) {}
extern "C" void fn_111_858C(void*) {}
extern "C" void fn_111_8590(void*) {}
extern "C" void fn_111_8594(void*) {}
extern "C" void fn_111_8598(void*) {}
extern "C" void fn_111_859C(void*) {}
extern "C" void fn_111_85A0(void*) {}
extern "C" void fn_111_85A4(void*) {}
extern "C" void fn_111_85A8(void*) {}
extern "C" void fn_111_85AC(void*) {}
extern "C" void fn_111_85B0(void*) {}

extern "C" int fn_111_85B4(void*) {
    return 0;
}

extern "C" void fn_111_85BC(void*) {}
extern "C" void fn_111_85C0(void*) {}
extern "C" void fn_111_85C4(void*) {}
extern "C" void fn_111_85C8(void*) {}

extern "C" void fn_111_85CC(void* observer, s16 manageId, s8 unitId) {
    fn_27_1A7908(observer, manageId, observer, unitId);
}

extern "C" void fn_111_85E0(void* observer, s16 manageId, s8 unitId) {
    fn_27_1A76C4(observer, manageId, observer, unitId);
}

extern "C" void fn_111_85F4(void*) {}
extern "C" void fn_111_85F8(void*) {}
extern "C" void fn_111_85FC(void*) {}
extern "C" void fn_111_8600(void*) {}
extern "C" void fn_111_8604(void*) {}

extern "C" ftKind fn_111_8608(const void* object) {
    return *reinterpret_cast<const ftKind*>(static_cast<const u8*>(object) + 0x110);
}

extern "C" int fn_111_8610(Fighter* fighter) {
    return fighter->getFtKind();
}

extern "C" u32 fn_111_8620(void*) {
    return 0;
}

extern "C" void fn_111_8628(void*) {}
extern "C" void fn_111_862C(void*) {}
extern "C" void fn_111_8630(void*) {}

extern "C" u32 fn_111_8634(void*) {
    return 0;
}

extern "C" u32 fn_111_863C(void*) {
    return 0;
}

extern "C" void fn_111_8644(void*) {}
extern "C" void fn_111_8648(void*) {}
extern "C" void fn_111_864C(void*) {}
extern "C" void fn_111_8650(void*) {}
extern "C" void fn_111_8654(void*) {}
extern "C" void fn_111_8658(void*) {}
