#pragma force_active on
void operator delete(void*);
extern "C" void* fn_112_3698(void*, short);
extern "C" void* fn_112_36F4(void*, short);
extern "C" void* fn_112_3750(void*, short);
extern "C" void* fn_112_37DC(void*, short);
extern "C" void* fn_112_EAB0(void*, short);
extern "C" void* fn_112_EB28(void*, short);
extern "C" void* fn_112_4A74(void*, short);
extern "C" void* fn_112_38D8(void*, short);
extern "C" void* fn_112_3934(void*, short);
extern "C" void* fn_112_3990(void*, short);
extern "C" void* fn_112_39FC(void*, short);
extern "C" void* fn_112_3A5C(void*, short);
extern "C" void* fn_112_3ABC(void*, short);
extern "C" void* fn_112_EC20(void*, short);
extern "C" void* fn_112_EC94(void*, short);
extern "C" void* fn_112_4BA8(void*, short);
extern "C" void* fn_112_3B18(void*, short);
extern "C" void* fn_112_4C2C(void*, short);
extern "C" void* fn_112_4CF4(void*, short);
extern "C" void* fn_112_ED74(void*, short);
extern "C" void* fn_112_3D68(void*, short);
extern "C" void* fn_112_3DD4(void*, short);
extern "C" void* fn_112_3E8C(void*, short);
extern "C" void* fn_112_3ECC(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_112_3F28(void*, short);

extern "C" void* fn_112_E924(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_3698(storage + 0x1c04, -1);
        fn_112_36F4(storage + 0x1bec, -1);
        fn_112_3750(storage + 0x1a50, -1);
        fn_112_37DC(storage + 0x19f0, -1);
        fn_112_EAB0(storage + 0x1800, -1);
        fn_112_EB28(storage + 0x1630, -1);
        fn_112_4A74(storage + 0x158c, -1);
        fn_112_38D8(storage + 0x1558, -1);
        fn_112_3934(storage + 0x1540, -1);
        fn_112_3990(storage + 0x13dc, -1);
        fn_112_39FC(storage + 0x1374, -1);
        fn_112_3A5C(storage + 0x1368, -1);
        fn_112_3ABC(storage + 0x1340, -1);
        fn_112_EC20(storage + 0x11e4, -1);
        fn_112_EC94(storage + 0x1038, -1);
        fn_112_4BA8(storage + 0xe74, -1);
        fn_112_3B18(storage + 0xe10, -1);
        fn_112_4C2C(storage + 0xdd4, -1);
        fn_112_4CF4(storage + 0xd1c, -1);
        fn_112_ED74(storage + 0xb10, -1);
        fn_112_3D68(storage + 0x930, -1);
        fn_112_3DD4(storage + 0x900, -1);
        fn_112_3E8C(storage + 0x8f0, -1);
        fn_112_3ECC(storage + 0x8d8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7f8, -1);
        fn_112_3F28(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
