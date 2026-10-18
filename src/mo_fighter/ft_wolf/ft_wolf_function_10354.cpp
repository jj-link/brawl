#pragma force_active on
extern "C" void fn_125_3C84(void*, short);
extern "C" void fn_125_3D08(void*, short);
extern "C" void fn_125_103F0(void*, short);
extern "C" void fn_125_3D68(void*, short);
extern "C" void fn_125_3E90(void*, short);
extern "C" void fn_27_C74E8(void*, short);
extern void operator delete(void*);

extern "C" void* fn_125_10354(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_125_3C84(storage + 0x118, -1);
        fn_125_3D08(storage + 0x104, -1);
        fn_125_103F0(storage + 0xec, -1);
        fn_125_3D68(storage + 0x48, -1);
        fn_125_3E90(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
