#pragma force_active on
extern "C" {
void* fn_126_29AC(void*, short);
void* fn_126_2A08(void*, short);
void* fn_126_2A64(void*, short);
void* fn_126_2AC0(void*, short);
void* fn_126_2B1C(void*, short);
void* fn_126_2B78(void*, short);
void* fn_126_2BD4(void*, short);
void* fn_126_2C30(void*, short);
void* fn_126_2CA4(void*, short);
void* fn_126_2D28(void*, short);
void* fn_126_2D84(void*, short);
void* fn_126_2ED4(void*, short);
void* fn_126_2FD0(void*, short);
void* fn_126_311C(void*, short);
void* fn_126_3E10(void*, short);
void* fn_126_3F48(void*, short);
void* fn_126_3FA4(void*, short);
void* fn_126_4018(void*, short);
void* fn_126_40F4(void*, short);
void* fn_126_4150(void*, short);
void* fn_126_41BC(void*, short);
void* fn_126_4268(void*, short);
void* fn_126_42DC(void*, short);
void* fn_126_4338(void*, short);
void* fn_126_4394(void*, short);
void* fn_126_43F0(void*, short);
void* fn_126_444C(void*, short);
void* fn_126_44C0(void*, short);
void* fn_126_452C(void*, short);
void* fn_126_45BC(void*, short);
void* fn_126_464C(void*, short);
void* fn_126_46D0(void*, short);
void* fn_126_4754(void*, short);
void* fn_126_4868(void*, short);
void* fn_126_48C4(void*, short);
void* fn_126_4930(void*, short);
void* fn_126_49A4(void*, short);
void* fn_126_4D68(void*, short);
void* fn_126_4E3C(void*, short);
void* fn_126_4EF4(void*, short);
void* fn_126_4F50(void*, short);
void* fn_126_4FAC(void*, short);
void __dl__FPv(void*);
void __dt__16soModuleAccesserFv(void*, short);
}

extern "C" void* fn_126_F118(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_126_29AC(storage + 0x62C8, -1);
        fn_126_2A08(storage + 0x628C, -1);
        fn_126_2A64(storage + 0x6224, -1);
        fn_126_2AC0(storage + 0x61D8, -1);
        fn_126_2B1C(storage + 0x6084, -1);
        fn_126_2B78(storage + 0x6038, -1);
        fn_126_2BD4(storage + 0x5FB8, -1);
        fn_126_2C30(storage + 0x5EF4, -1);
        fn_126_2CA4(storage + 0x5C64, -1);
        fn_126_2D28(storage + 0x5C34, -1);
        fn_126_2D84(storage + 0x5A90, -1);
        fn_126_2ED4(storage + 0x58A8, -1);
        fn_126_2FD0(storage + 0x55A0, -1);
        fn_126_311C(storage + 0x4740, -1);
        fn_126_3E10(storage + 0x464C, -1);
        fn_126_3F48(storage + 0x4618, -1);
        fn_126_3FA4(storage + 0x45A4, -1);
        fn_126_4018(storage + 0x3E80, -1);
        fn_126_40F4(storage + 0x3E50, -1);
        fn_126_4150(storage + 0x3CB8, -1);
        fn_126_41BC(storage + 0x3C48, -1);
        fn_126_4268(storage + 0x3BB0, -1);
        fn_126_42DC(storage + 0x3B78, -1);
        fn_126_4338(storage + 0x3B54, -1);
        fn_126_4394(storage + 0x3B20, -1);
        fn_126_43F0(storage + 0x3ABC, -1);
        fn_126_444C(storage + 0x390C, -1);
        fn_126_44C0(storage + 0x36A8, -1);
        fn_126_452C(storage + 0x2C3C, -1);
        fn_126_45BC(storage + 0x2A24, -1);
        fn_126_464C(storage + 0x20C8, -1);
        fn_126_46D0(storage + 0x1A0C, -1);
        fn_126_4754(storage + 0x1998, -1);
        fn_126_4868(storage + 0x195C, -1);
        fn_126_48C4(storage + 0x18B4, -1);
        fn_126_4930(storage + 0x1800, -1);
        fn_126_49A4(storage + 0x1440, -1);
        fn_126_4D68(storage + 0x1180, -1);
        fn_126_4E3C(storage + 0x115C, -1);
        fn_126_4EF4(storage + 0xAC8, -1);
        fn_126_4F50(storage + 0xAB0, -1);
        __dt__16soModuleAccesserFv(storage + 0x9D0, -1);
        fn_126_4FAC(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}