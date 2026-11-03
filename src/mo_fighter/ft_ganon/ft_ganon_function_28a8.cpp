#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_109_2B48(void*, short);
void* fn_109_2BA4(void*, short);
void* fn_109_2C00(void*, short);
void* fn_109_2C5C(void*, short);
void* fn_109_2CB8(void*, short);
void* fn_109_2D14(void*, short);
void* fn_109_2DF0(void*, short);
void* fn_109_2E4C(void*, short);
void* fn_109_2EA8(void*, short);
void* fn_109_2F1C(void*, short);
void* fn_109_2FB4(void*, short);
void* fn_109_3010(void*, short);
void* fn_109_3160(void*, short);
void* fn_109_4AE4(void*, short);
void* fn_109_4B44(void*, short);
void* fn_109_4C98(void*, short);
void* fn_109_5808(void*, short);
void* fn_109_3F44(void*, short);
void* fn_109_3FA0(void*, short);
void* fn_109_58E4(void*, short);
void* fn_109_59C0(void*, short);
void* fn_109_5A1C(void*, short);
void* fn_109_5A88(void*, short);
void* fn_109_5B34(void*, short);
void* fn_109_5BA8(void*, short);
void* fn_109_5C04(void*, short);
void* fn_109_5C60(void*, short);
void* fn_109_5CBC(void*, short);
void* fn_109_5D18(void*, short);
void* fn_109_5D8C(void*, short);
void* fn_109_5DF8(void*, short);
void* fn_109_5E88(void*, short);
void* fn_109_40E0(void*, short);
void* fn_109_5F18(void*, short);
void* fn_109_5F9C(void*, short);
void* fn_109_4230(void*, short);
void* fn_109_60D0(void*, short);
void* fn_109_428C(void*, short);
void* fn_109_613C(void*, short);
void* fn_109_64A4(void*, short);
void* fn_109_6578(void*, short);
void* fn_109_65F0(void*, short);
void* fn_109_4548(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_109_664C(void*, short);
}

extern "C" void* fn_109_28A8(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_109_2B48(storage + 0xAAE0, destroy);
        fn_109_2BA4(storage + 0xAAA4, destroy);
        fn_109_2C00(storage + 0xAA3C, destroy);
        fn_109_2C5C(storage + 0xA9F0, destroy);
        fn_109_2CB8(storage + 0xA89C, destroy);
        fn_109_2D14(storage + 0xA78C, destroy);
        fn_109_2DF0(storage + 0xA744, destroy);
        fn_109_2E4C(storage + 0xA6C4, destroy);
        fn_109_2EA8(storage + 0xA600, destroy);
        fn_109_2F1C(storage + 0xA28C, destroy);
        fn_109_2FB4(storage + 0xA25C, destroy);
        fn_109_3010(storage + 0xA0B8, destroy);
        fn_109_3160(storage + 0x5A88, destroy);
        fn_109_4AE4(storage + 0x58A4, destroy);
        fn_109_4B44(storage + 0x559C, destroy);
        fn_109_4C98(storage + 0x4714, destroy);
        fn_109_5808(storage + 0x4620, destroy);
        fn_109_3F44(storage + 0x45EC, destroy);
        fn_109_3FA0(storage + 0x4578, destroy);
        fn_109_58E4(storage + 0x3E54, destroy);
        fn_109_59C0(storage + 0x3E24, destroy);
        fn_109_5A1C(storage + 0x3C8C, destroy);
        fn_109_5A88(storage + 0x3C1C, destroy);
        fn_109_5B34(storage + 0x3B84, destroy);
        fn_109_5BA8(storage + 0x3B4C, destroy);
        fn_109_5C04(storage + 0x3B28, destroy);
        fn_109_5C60(storage + 0x3AF4, destroy);
        fn_109_5CBC(storage + 0x3A90, destroy);
        fn_109_5D18(storage + 0x38E0, destroy);
        fn_109_5D8C(storage + 0x367C, destroy);
        fn_109_5DF8(storage + 0x2C10, destroy);
        fn_109_5E88(storage + 0x29F8, destroy);
        fn_109_40E0(storage + 0x209C, destroy);
        fn_109_5F18(storage + 0x19E0, destroy);
        fn_109_5F9C(storage + 0x196C, destroy);
        fn_109_4230(storage + 0x1930, destroy);
        fn_109_60D0(storage + 0x1888, destroy);
        fn_109_428C(storage + 0x17D4, destroy);
        fn_109_613C(storage + 0x1440, destroy);
        fn_109_64A4(storage + 0x1180, destroy);
        fn_109_6578(storage + 0x115C, destroy);
        fn_109_65F0(storage + 0xAC8, destroy);
        fn_109_4548(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_109_664C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
