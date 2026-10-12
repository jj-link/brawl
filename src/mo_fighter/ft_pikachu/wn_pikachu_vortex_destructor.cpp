#include <so/so_module_accesser.h>

extern "C" {
void* fn_98_38F0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_98_3AEC(void*, short);
void* fn_98_2138(void*, short);
void* fn_98_21D4(void*, short);
void* fn_98_2214(void*, short);
void* fn_27_C7770(void*, short);
void* fn_98_3BB4(void*, short);
void* fn_98_3C10(void*, short);
void* fn_98_3C6C(void*, short);
void* fn_98_3F10(void*, short);
void* fn_98_3FAC(void*, short);
void* fn_98_418C(void*, short);
void* fn_98_4210(void*, short);
void* fn_27_1A405C(void*, short);
void* fn_98_4270(void*, short);
void* fn_98_4398(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_98_43F8(void*, short);
void* fn_98_452C(void*, short);
void* fn_98_5384(void*, short);
void* fn_98_4588(void*, short);
void* fn_98_45E4(void*, short);
void* fn_98_4650(void*, short);
void* fn_98_46B0(void*, short);
void* fn_98_4710(void*, short);
void* fn_98_4E20(void*, short);
void* fn_98_476C(void*, short);
void* fn_98_4838(void*, short);
void* fn_98_4900(void*, short);
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_98_49EC(void*, short);
void* fn_98_4A74(void*, short);
void* fn_98_4AE0(void*, short);
void* fn_98_4B98(void*, short);
void* fn_98_4BD8(void*, short);
void* fn_98_4C34(void*, short);
void* fn_27_1D81C8(void*, short);
}

#pragma always_inline on
#pragma inline_depth(8)

// Embedded aggregate destruction retains each subobject's null guard.
static inline void destroyCollisionGroup(char* group) {
    if (group) {
        short deleting = -1;
        fn_98_2138(group + 0xdc, deleting);
        fn_98_21D4(group + 0xc0, deleting);
        fn_98_2214(group + 0x14, deleting);
        if (group) fn_27_C7770(group, deleting);
    }
}

static inline void destroyCollisionStorage(char* storage) {
    if (storage) {
        fn_98_3AEC(storage + 0x4b0, static_cast<short>(-1));
        destroyCollisionGroup(storage + 0x384);
        destroyCollisionGroup(storage + 0x258);
        destroyCollisionGroup(storage + 0x12c);
        destroyCollisionGroup(storage);
    }
}

static inline void destroyModuleStorage(char* storage) {
    if (storage) {
        short deleting = -1;
        fn_98_3BB4(storage + 0x183c, deleting);
        fn_98_3C10(storage + 0x1824, deleting);
        fn_98_3C6C(storage + 0x1688, deleting);
        if (storage + 0x1624) fn_98_3F10(storage + 0x1660, deleting);
        fn_98_3FAC(storage + 0x1570, deleting);
        if (storage + 0x13a8) {
            fn_98_418C(storage + 0x14c0, deleting);
            fn_98_4210(storage + 0x14ac, deleting);
            if (storage + 0x1494) fn_27_1A405C(storage + 0x1494, deleting);
            fn_98_4270(storage + 0x13f0, deleting);
            fn_98_4398(storage + 0x13b8, deleting);
            fn_27_C74E8(storage + 0x13a8, deleting);
        }
        fn_98_43F8(storage + 0x1304, deleting);
        fn_98_452C(storage + 0x12d0, deleting);
        fn_98_5384(storage + 0x125c, deleting);
        fn_98_4588(storage + 0x1244, deleting);
        fn_98_45E4(storage + 0x10e0, deleting);
        fn_98_4650(storage + 0x1078, deleting);
        fn_98_46B0(storage + 0x106c, deleting);
        fn_98_4710(storage + 0x1044, deleting);
        fn_98_4E20(storage + 0xe74, deleting);
        fn_98_476C(storage + 0xe10, deleting);
        fn_98_4838(storage + 0xdd4, deleting);
        fn_98_4900(storage + 0xd1c, deleting);
        if (storage + 0xb10) {
            fn_27_13C90(storage + 0xbac, deleting);
            fn_27_21038(storage + 0xb98, deleting);
            fn_98_49EC(storage + 0xb10, deleting);
        }
        fn_98_4A74(storage + 0x930, deleting);
        fn_98_4AE0(storage + 0x900, deleting);
        fn_98_4B98(storage + 0x8f0, deleting);
        fn_98_4BD8(storage + 0x8d8, deleting);
        reinterpret_cast<soModuleAccesser*>(storage + 0x7f8)->soModuleAccesser::~soModuleAccesser();
        fn_98_4C34(storage, deleting);
    }
}

static inline void destroyWeapon(char* weapon) {
    if (weapon) {
        short deleting = -1;
        fn_98_38F0(weapon + 0x1f34, deleting);
        fn_27_1DBB60(weapon + 0x1efc, deleting);
        if (weapon + 0xcc) {
            destroyCollisionStorage(weapon + 0x194c);
            destroyModuleStorage(weapon + 0xcc);
        }
        fn_27_1D81C8(weapon, static_cast<short>(0));
    }
}

extern "C" void* fn_98_5034(void* object, int deleting) {
    if (object) {
        destroyWeapon(static_cast<char*>(object));
        if (static_cast<short>(deleting) > 0) operator delete(object);
    }
    return object;
}
