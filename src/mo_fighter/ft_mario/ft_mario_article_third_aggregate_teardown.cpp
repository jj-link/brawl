extern "C" {
void* fn_91_6308(void*, short);
void* fn_91_6364(void*, short);
void* fn_91_63C0(void*, short);
void* fn_91_64A8(void*, short);
void* fn_91_6508(void*, short);
void* fn_91_18B20(void*, short);
void* fn_91_668C(void*, short);
void* fn_91_2258(void*, short);
void* fn_91_6714(void*, short);
void* fn_91_6770(void*, short);
void* fn_91_67DC(void*, short);
void* fn_91_683C(void*, short);
void* fn_91_689C(void*, short);
void* fn_91_18C18(void*, short);
void* fn_91_68F8(void*, short);
void* fn_91_203C(void*, short);
void* fn_91_1F5C(void*, short);
void* fn_91_18C9C(void*, short);
void* fn_91_6A0C(void*, short);
void* fn_91_6A78(void*, short);
void* fn_91_6AF0(void*, short);
void* fn_91_1F00(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_91_6B30(void*, short);

void* fn_91_189AC(void* object, short deleting) {
    if (object != 0) {
        fn_91_6308(static_cast<unsigned char*>(object) + 0x184c, static_cast<short>(-1));
        fn_91_6364(static_cast<unsigned char*>(object) + 0x1834, static_cast<short>(-1));
        fn_91_63C0(static_cast<unsigned char*>(object) + 0x1698, static_cast<short>(-1));
        fn_91_64A8(static_cast<unsigned char*>(object) + 0x1638, static_cast<short>(-1));
        fn_91_6508(static_cast<unsigned char*>(object) + 0x1584, static_cast<short>(-1));
        fn_91_18B20(static_cast<unsigned char*>(object) + 0x13c4, static_cast<short>(-1));
        fn_91_668C(static_cast<unsigned char*>(object) + 0x1320, static_cast<short>(-1));
        fn_91_2258(static_cast<unsigned char*>(object) + 0x12ec, static_cast<short>(-1));
        fn_91_6714(static_cast<unsigned char*>(object) + 0x12d4, static_cast<short>(-1));
        fn_91_6770(static_cast<unsigned char*>(object) + 0x1170, static_cast<short>(-1));
        fn_91_67DC(static_cast<unsigned char*>(object) + 0x1108, static_cast<short>(-1));
        fn_91_683C(static_cast<unsigned char*>(object) + 0x10fc, static_cast<short>(-1));
        fn_91_689C(static_cast<unsigned char*>(object) + 0x10d4, static_cast<short>(-1));
        fn_91_18C18(static_cast<unsigned char*>(object) + 0xe74, static_cast<short>(-1));
        fn_91_68F8(static_cast<unsigned char*>(object) + 0xe10, static_cast<short>(-1));
        fn_91_203C(static_cast<unsigned char*>(object) + 0xdd4, static_cast<short>(-1));
        fn_91_1F5C(static_cast<unsigned char*>(object) + 0xd1c, static_cast<short>(-1));
        fn_91_18C9C(static_cast<unsigned char*>(object) + 0xb10, static_cast<short>(-1));
        fn_91_6A0C(static_cast<unsigned char*>(object) + 0x930, static_cast<short>(-1));
        fn_91_6A78(static_cast<unsigned char*>(object) + 0x900, static_cast<short>(-1));
        fn_91_6AF0(static_cast<unsigned char*>(object) + 0x8f0, static_cast<short>(-1));
        fn_91_1F00(static_cast<unsigned char*>(object) + 0x8d8, static_cast<short>(-1));
        __dt__16soModuleAccesserFv(static_cast<unsigned char*>(object) + 0x7f8, static_cast<short>(-1));
        fn_91_6B30(object, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
