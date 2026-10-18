#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_394C(void*, short);
void* fn_116_39A8(void*, short);
void* fn_116_3A04(void*, short);
void* fn_116_3A60(void*, short);
void* fn_116_132B0(void*, short);
void* fn_116_3B68(void*, short);
void* fn_116_13310(void*, short);
void* fn_116_3D88(void*, short);
void* fn_116_3EBC(void*, short);
void* fn_116_13388(void*, short);
void* fn_116_3F18(void*, short);
void* fn_116_3F84(void*, short);
void* fn_116_3FE4(void*, short);
void* fn_116_4040(void*, short);
void* fn_116_40C4(void*, short);
void* fn_116_4190(void*, short);
void* fn_116_41EC(void*, short);
void* fn_116_4258(void*, short);
void* fn_116_133E4(void*, short);
void* fn_116_4C04(void*, short);
void* fn_116_4C70(void*, short);
void* fn_116_42CC(void*, short);
void* fn_116_430C(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_116_13450(void*, short);
}

extern "C" void* fn_116_13130(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_394C(storage + 0x1254, -1);
        fn_116_39A8(storage + 0x1214, -1);
        fn_116_3A04(storage + 0x11FC, -1);
        fn_116_3A60(storage + 0x10A4, -1);
        fn_116_132B0(storage + 0x1038, -1);
        fn_116_3B68(storage + 0xFCC, -1);
        fn_116_13310(storage + 0xEF4, -1);
        fn_116_3D88(storage + 0xE50, -1);
        fn_116_3EBC(storage + 0xE1C, -1);
        fn_116_13388(storage + 0xDE8, -1);
        fn_116_3F18(storage + 0xC84, -1);
        fn_116_3F84(storage + 0xC74, -1);
        fn_116_3FE4(storage + 0xC4C, -1);
        fn_116_4040(storage + 0xA7C, -1);
        fn_116_40C4(storage + 0xA18, -1);
        fn_116_4190(storage + 0x9DC, -1);
        fn_116_41EC(storage + 0x934, -1);
        fn_116_4258(storage + 0x880, -1);
        fn_116_133E4(storage + 0x6F4, -1);
        fn_116_4C04(storage + 0x5B0, -1);
        fn_116_4C70(storage + 0x580, -1);
        fn_116_42CC(storage + 0x570, -1);
        fn_116_430C(storage + 0x558, -1);
        __dt__16soModuleAccesserFv(storage + 0x478, -1);
        fn_116_13450(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
