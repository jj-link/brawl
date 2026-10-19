#pragma force_active on
void operator delete(void*);

extern "C" void* fn_108_4CC0(void*, short);
extern "C" void* fn_108_39A4(void*, short);
extern "C" void* fn_108_3A00(void*, short);
extern "C" void* fn_108_3A8C(void*, short);
extern "C" void* fn_108_4D78(void*, short);
extern "C" void* fn_108_10364(void*, short);
extern "C" void* fn_108_3E98(void*, short);
extern "C" void* fn_108_3FCC(void*, short);
extern "C" void* fn_108_4028(void*, short);
extern "C" void* fn_108_4084(void*, short);
extern "C" void* fn_108_40F0(void*, short);
extern "C" void* fn_108_4150(void*, short);
extern "C" void* fn_108_41B0(void*, short);
extern "C" void* fn_108_1045C(void*, short);
extern "C" void* fn_108_420C(void*, short);
extern "C" void* fn_108_42D8(void*, short);
extern "C" void* fn_108_4334(void*, short);
extern "C" void* fn_108_1053C(void*, short);
extern "C" void* fn_108_448C(void*, short);
extern "C" void* fn_108_44F8(void*, short);
extern "C" void* fn_108_45B0(void*, short);
extern "C" void* fn_108_45F0(void*, short);
extern "C" void* __dt__16soModuleAccesserFv(void*, short);
extern "C" void* fn_108_464C(void*, short);

extern "C" void* fn_108_101F0(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_108_4CC0(static_cast<unsigned char*>(object) + 0x1858, -1);
        fn_108_39A4(storage + 0x183c, -1);
        fn_108_3A00(storage + 0x16a0, -1);
        fn_108_3A8C(storage + 0x1640, -1);
        fn_108_4D78(storage + 0x158c, -1);
        fn_108_10364(storage + 0x13c4, -1);
        fn_108_3E98(storage + 0x1320, -1);
        fn_108_3FCC(storage + 0x12ec, -1);
        fn_108_4028(storage + 0x12d4, -1);
        fn_108_4084(storage + 0x1170, -1);
        fn_108_40F0(storage + 0x1108, -1);
        fn_108_4150(storage + 0x10fc, -1);
        fn_108_41B0(storage + 0x10d4, -1);
        fn_108_1045C(storage + 0xe74, -1);
        fn_108_420C(storage + 0xe10, -1);
        fn_108_42D8(storage + 0xdd4, -1);
        fn_108_4334(storage + 0xd1c, -1);
        fn_108_1053C(storage + 0xb10, -1);
        fn_108_448C(storage + 0x930, -1);
        fn_108_44F8(storage + 0x900, -1);
        fn_108_45B0(storage + 0x8f0, -1);
        fn_108_45F0(storage + 0x8d8, -1);
        __dt__16soModuleAccesserFv(storage + 0x7f8, -1);
        fn_108_464C(storage + 0x0, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
