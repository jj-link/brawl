#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_123_2B6C(void*, short);
void* fn_123_2BC8(void*, short);
void* fn_123_2C24(void*, short);
void* fn_123_2C80(void*, short);
void* fn_123_2CDC(void*, short);
void* fn_123_2D38(void*, short);
void* fn_123_2E14(void*, short);
void* fn_123_2E70(void*, short);
void* fn_123_2ECC(void*, short);
void* fn_123_2F40(void*, short);
void* fn_123_2FD8(void*, short);
void* fn_123_3034(void*, short);
void* fn_123_3184(void*, short);
void* fn_123_5154(void*, short);
void* fn_123_51B4(void*, short);
void* fn_123_522C(void*, short);
void* fn_123_5D9C(void*, short);
void* fn_123_40D4(void*, short);
void* fn_123_4F40(void*, short);
void* fn_123_5E78(void*, short);
void* fn_123_5F54(void*, short);
void* fn_123_5FB0(void*, short);
void* fn_123_601C(void*, short);
void* fn_123_60C8(void*, short);
void* fn_123_613C(void*, short);
void* fn_123_6198(void*, short);
void* fn_123_61F4(void*, short);
void* fn_123_6250(void*, short);
void* fn_123_62AC(void*, short);
void* fn_123_6320(void*, short);
void* fn_123_6398(void*, short);
void* fn_123_6404(void*, short);
void* fn_123_6494(void*, short);
void* fn_123_4FB4(void*, short);
void* fn_123_6524(void*, short);
void* fn_123_65A8(void*, short);
void* fn_123_4464(void*, short);
void* fn_123_44C0(void*, short);
void* fn_123_452C(void*, short);
void* fn_123_66DC(void*, short);
void* fn_123_6A44(void*, short);
void* fn_123_6B18(void*, short);
void* fn_123_6B90(void*, short);
void* fn_123_478C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_123_6BEC(void*, short);
}

extern "C" void* fn_123_28C0(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_123_2B6C(storage + 0xB6E8, destroy);
        fn_123_2BC8(storage + 0xB6AC, destroy);
        fn_123_2C24(storage + 0xB644, destroy);
        fn_123_2C80(storage + 0xB5F8, destroy);
        fn_123_2CDC(storage + 0xB4A4, destroy);
        fn_123_2D38(storage + 0xB394, destroy);
        fn_123_2E14(storage + 0xB34C, destroy);
        fn_123_2E70(storage + 0xB2CC, destroy);
        fn_123_2ECC(storage + 0xB208, destroy);
        fn_123_2F40(storage + 0xAE94, destroy);
        fn_123_2FD8(storage + 0xAE64, destroy);
        fn_123_3034(storage + 0xACC0, destroy);
        fn_123_3184(storage + 0x5CC4, destroy);
        fn_123_5154(storage + 0x5AE0, destroy);
        fn_123_51B4(storage + 0x57D8, destroy);
        fn_123_522C(storage + 0x493C, destroy);
        fn_123_5D9C(storage + 0x4848, destroy);
        fn_123_40D4(storage + 0x4814, destroy);
        fn_123_4F40(storage + 0x47A0, destroy);
        fn_123_5E78(storage + 0x407C, destroy);
        fn_123_5F54(storage + 0x404C, destroy);
        fn_123_5FB0(storage + 0x3E80, destroy);
        fn_123_601C(storage + 0x3E10, destroy);
        fn_123_60C8(storage + 0x3D78, destroy);
        fn_123_613C(storage + 0x3D40, destroy);
        fn_123_6198(storage + 0x3D1C, destroy);
        fn_123_61F4(storage + 0x3CE8, destroy);
        fn_123_6250(storage + 0x3C84, destroy);
        fn_123_62AC(storage + 0x3AD4, destroy);
        fn_123_6320(storage + 0x38DC, destroy);
        fn_123_6398(storage + 0x367C, destroy);
        fn_123_6404(storage + 0x2C10, destroy);
        fn_123_6494(storage + 0x29F8, destroy);
        fn_123_4FB4(storage + 0x209C, destroy);
        fn_123_6524(storage + 0x19E0, destroy);
        fn_123_65A8(storage + 0x196C, destroy);
        fn_123_4464(storage + 0x1930, destroy);
        fn_123_44C0(storage + 0x1888, destroy);
        fn_123_452C(storage + 0x17D4, destroy);
        fn_123_66DC(storage + 0x1440, destroy);
        fn_123_6A44(storage + 0x1180, destroy);
        fn_123_6B18(storage + 0x115C, destroy);
        fn_123_6B90(storage + 0xAC8, destroy);
        fn_123_478C(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_123_6BEC(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}