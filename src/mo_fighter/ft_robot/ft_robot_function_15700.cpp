#pragma force_active on
extern "C" void fn_120_3CA0(void*, short);
extern "C" void fn_120_3D24(void*, short);
extern "C" void fn_120_12BB4(void*, short);
extern "C" void fn_120_12B3C(void*, short);
extern "C" void fn_120_156A0(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_120_15700(void* object, short deleting) {
    if (object != 0) {
        fn_120_3CA0(static_cast<unsigned char*>(object) + 0x11c, -1);
        fn_120_3D24(static_cast<unsigned char*>(object) + 0x108, -1);
        fn_120_12BB4(static_cast<unsigned char*>(object) + 0xf0, -1);
        fn_120_12B3C(static_cast<unsigned char*>(object) + 0x4c, -1);
        fn_120_156A0(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
