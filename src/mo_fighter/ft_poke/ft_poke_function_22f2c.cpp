#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_394C(void*, short);
void* fn_116_39A8(void*, short);
void* fn_116_3A04(void*, short);
void* fn_116_3A60(void*, short);
void* fn_116_230AC(void*, short);
void* fn_116_3B68(void*, short);
void* fn_116_2310C(void*, short);
void* fn_116_3D88(void*, short);
void* fn_116_3EBC(void*, short);
void* fn_116_FEE8(void*, short);
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
void* fn_116_1DAF8(void*, short);
}

extern "C" void* fn_116_22F2C(void* object, short deleting) {
    if (object) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_116_394C(p + 0x120c, -1);
        fn_116_39A8(p + 0x11cc, -1);
        fn_116_3A04(p + 0x11b4, -1);
        fn_116_3A60(p + 0x105c, -1);
        fn_116_230AC(p + 0xfe0, -1);
        fn_116_3B68(p + 0xf74, -1);
        fn_116_2310C(p + 0xe88, -1);
        fn_116_3D88(p + 0xde4, -1);
        fn_116_3EBC(p + 0xdb0, -1);
        fn_116_FEE8(p + 0xd98, -1);
        fn_116_3F18(p + 0xc34, -1);
        fn_116_3F84(p + 0xc24, -1);
        fn_116_3FE4(p + 0xbfc, -1);
        fn_116_4040(p + 0xa2c, -1);
        fn_116_40C4(p + 0x9c8, -1);
        fn_116_4190(p + 0x98c, -1);
        fn_116_41EC(p + 0x8e4, -1);
        fn_116_4258(p + 0x830, -1);
        fn_116_133E4(p + 0x6a4, -1);
        fn_116_4C04(p + 0x560, -1);
        fn_116_4C70(p + 0x530, -1);
        fn_116_42CC(p + 0x520, -1);
        fn_116_430C(p + 0x508, -1);
        __dt__16soModuleAccesserFv(p + 0x428, -1);
        fn_116_1DAF8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
