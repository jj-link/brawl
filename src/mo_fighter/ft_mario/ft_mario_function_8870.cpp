#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_91_8814(void*, short);
void* fn_91_87B8(void*, short);
void* fn_91_875C(void*, short);
void* fn_91_8700(void*, short);
void* fn_91_86A4(void*, short);
void* fn_91_8624(void*, short);
void* fn_91_84F0(void*, short);
void* fn_91_8494(void*, short);
void* fn_91_8420(void*, short);
void* fn_91_8328(void*, short);
void* fn_91_8234(void*, short);
void* fn_91_819C(void*, short);
void* fn_91_7FEC(void*, short);
void* fn_91_5948(void*, short);
void* fn_91_5870(void*, short);
void* fn_91_5288(void*, short);
void* fn_91_4110(void*, short);
void* fn_91_2258(void*, short);
void* fn_91_3F3C(void*, short);
void* fn_91_3E50(void*, short);
void* fn_91_3D28(void*, short);
void* fn_91_3CBC(void*, short);
void* fn_91_3BFC(void*, short);
void* fn_91_3AB8(void*, short);
void* fn_91_3A00(void*, short);
void* fn_91_39A4(void*, short);
void* fn_91_3948(void*, short);
void* fn_91_38EC(void*, short);
void* fn_91_3878(void*, short);
void* fn_91_37A0(void*, short);
void* fn_91_3678(void*, short);
void* fn_91_3514(void*, short);
void* fn_91_33BC(void*, short);
void* fn_91_3274(void*, short);
void* fn_91_3138(void*, short);
void* fn_91_203C(void*, short);
void* fn_91_1FD0(void*, short);
void* fn_91_1F5C(void*, short);
void* fn_91_2FB0(void*, short);
void* fn_91_29B4(void*, short);
void* fn_91_2858(void*, short);
void* fn_91_2754(void*, short);
void* fn_91_1F00(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_91_2610(void*, short);
}

extern "C" void* fn_91_8870(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_91_8814(storage + 0x2BD64, destroy);
        fn_91_87B8(storage + 0x2BD28, destroy);
        fn_91_875C(storage + 0x2BCC0, destroy);
        fn_91_8700(storage + 0x2BC74, destroy);
        fn_91_86A4(storage + 0x2BB20, destroy);
        fn_91_8624(storage + 0x2BA10, destroy);
        fn_91_84F0(storage + 0x2B9C8, destroy);
        fn_91_8494(storage + 0x2B948, destroy);
        fn_91_8420(storage + 0x2B884, destroy);
        fn_91_8328(storage + 0x2B510, destroy);
        fn_91_8234(storage + 0x2B4E0, destroy);
        fn_91_819C(storage + 0x2B33C, destroy);
        fn_91_7FEC(storage + 0x5894, destroy);
        fn_91_5948(storage + 0x56B0, destroy);
        fn_91_5870(storage + 0x53A8, destroy);
        fn_91_5288(storage + 0x4544, destroy);
        fn_91_4110(storage + 0x4450, destroy);
        fn_91_2258(storage + 0x441C, destroy);
        fn_91_3F3C(storage + 0x43A8, destroy);
        fn_91_3E50(storage + 0x3C84, destroy);
        fn_91_3D28(storage + 0x3C54, destroy);
        fn_91_3CBC(storage + 0x3ABC, destroy);
        fn_91_3BFC(storage + 0x3A4C, destroy);
        fn_91_3AB8(storage + 0x39B4, destroy);
        fn_91_3A00(storage + 0x397C, destroy);
        fn_91_39A4(storage + 0x3958, destroy);
        fn_91_3948(storage + 0x3924, destroy);
        fn_91_38EC(storage + 0x38C0, destroy);
        fn_91_3878(storage + 0x3710, destroy);
        fn_91_37A0(storage + 0x34AC, destroy);
        fn_91_3678(storage + 0x2C10, destroy);
        fn_91_3514(storage + 0x29F8, destroy);
        fn_91_33BC(storage + 0x209C, destroy);
        fn_91_3274(storage + 0x19E0, destroy);
        fn_91_3138(storage + 0x196C, destroy);
        fn_91_203C(storage + 0x1930, destroy);
        fn_91_1FD0(storage + 0x1888, destroy);
        fn_91_1F5C(storage + 0x17D4, destroy);
        fn_91_2FB0(storage + 0x1440, destroy);
        fn_91_29B4(storage + 0x1180, destroy);
        fn_91_2858(storage + 0x115C, destroy);
        fn_91_2754(storage + 0x0AC8, destroy);
        fn_91_1F00(storage + 0x0AB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x09D0, destroy);
        fn_91_2610(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
