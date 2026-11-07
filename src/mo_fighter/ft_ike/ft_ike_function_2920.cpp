#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_119_2BCC(void*, short);
void* fn_119_2C28(void*, short);
void* fn_119_2C84(void*, short);
void* fn_119_2CE0(void*, short);
void* fn_119_2D3C(void*, short);
void* fn_119_2D98(void*, short);
void* fn_119_2E74(void*, short);
void* fn_119_2ED0(void*, short);
void* fn_119_2F2C(void*, short);
void* fn_119_2FA0(void*, short);
void* fn_119_3038(void*, short);
void* fn_119_3094(void*, short);
void* fn_119_31E4(void*, short);
void* fn_119_3578(void*, short);
void* fn_119_3674(void*, short);
void* fn_119_37C0(void*, short);
void* fn_119_44B4(void*, short);
void* fn_119_45EC(void*, short);
void* fn_119_4648(void*, short);
void* fn_119_46BC(void*, short);
void* fn_119_4798(void*, short);
void* fn_119_47F4(void*, short);
void* fn_119_4860(void*, short);
void* fn_119_490C(void*, short);
void* fn_119_4980(void*, short);
void* fn_119_49DC(void*, short);
void* fn_119_4A38(void*, short);
void* fn_119_4A94(void*, short);
void* fn_119_4AF0(void*, short);
void* fn_119_4B64(void*, short);
void* fn_119_4BDC(void*, short);
void* fn_119_4C48(void*, short);
void* fn_119_4CD8(void*, short);
void* fn_119_4D68(void*, short);
void* fn_119_4DEC(void*, short);
void* fn_119_4E70(void*, short);
void* fn_119_4F84(void*, short);
void* fn_119_4FE0(void*, short);
void* fn_119_504C(void*, short);
void* fn_119_50C0(void*, short);
void* fn_119_5484(void*, short);
void* fn_119_5558(void*, short);
void* fn_119_5610(void*, short);
void* fn_119_566C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_119_56C8(void*, short);
}

extern "C" void* fn_119_2920(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_119_2BCC(storage + 0x8C8C, destroy);
        fn_119_2C28(storage + 0x8C50, destroy);
        fn_119_2C84(storage + 0x8BE8, destroy);
        fn_119_2CE0(storage + 0x8B9C, destroy);
        fn_119_2D3C(storage + 0x8A48, destroy);
        fn_119_2D98(storage + 0x8938, destroy);
        fn_119_2E74(storage + 0x88F0, destroy);
        fn_119_2ED0(storage + 0x8870, destroy);
        fn_119_2F2C(storage + 0x87AC, destroy);
        fn_119_2FA0(storage + 0x8438, destroy);
        fn_119_3038(storage + 0x8408, destroy);
        fn_119_3094(storage + 0x8264, destroy);
        fn_119_31E4(storage + 0x5EE0, destroy);
        fn_119_3578(storage + 0x5CFC, destroy);
        fn_119_3674(storage + 0x59F4, destroy);
        fn_119_37C0(storage + 0x4B2C, destroy);
        fn_119_44B4(storage + 0x4A38, destroy);
        fn_119_45EC(storage + 0x4A04, destroy);
        fn_119_4648(storage + 0x4990, destroy);
        fn_119_46BC(storage + 0x426C, destroy);
        fn_119_4798(storage + 0x423C, destroy);
        fn_119_47F4(storage + 0x4070, destroy);
        fn_119_4860(storage + 0x4000, destroy);
        fn_119_490C(storage + 0x3F68, destroy);
        fn_119_4980(storage + 0x3F30, destroy);
        fn_119_49DC(storage + 0x3F0C, destroy);
        fn_119_4A38(storage + 0x3ED8, destroy);
        fn_119_4A94(storage + 0x3E74, destroy);
        fn_119_4AF0(storage + 0x3CC4, destroy);
        fn_119_4B64(storage + 0x3A6C, destroy);
        fn_119_4BDC(storage + 0x380C, destroy);
        fn_119_4C48(storage + 0x2DA0, destroy);
        fn_119_4CD8(storage + 0x29F8, destroy);
        fn_119_4D68(storage + 0x209C, destroy);
        fn_119_4DEC(storage + 0x19E0, destroy);
        fn_119_4E70(storage + 0x196C, destroy);
        fn_119_4F84(storage + 0x1930, destroy);
        fn_119_4FE0(storage + 0x1888, destroy);
        fn_119_504C(storage + 0x17D4, destroy);
        fn_119_50C0(storage + 0x1440, destroy);
        fn_119_5484(storage + 0x1180, destroy);
        fn_119_5558(storage + 0x115C, destroy);
        fn_119_5610(storage + 0xAC8, destroy);
        fn_119_566C(storage + 0xAB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x9D0, destroy);
        fn_119_56C8(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
