#pragma force_active on
extern "C" void* fn_125_3C84(void*, short);
extern "C" void* fn_125_3D08(void*, short);
extern "C" void* fn_125_6574(void*, short);
extern "C" void* fn_125_65D0(void*, short);
extern "C" void* fn_125_6FE8(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

void operator delete(void*);

extern "C" void* fn_125_64D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short arg = -1;
        fn_125_3C84(storage + 0xdd0, arg);
        fn_125_3D08(storage + 0xdbc, arg);
        fn_125_6574(storage + 0x930, arg);
        fn_125_65D0(storage + 0xbc, arg);
        fn_125_6FE8(storage + 0x10, arg);
        fn_27_C74E8(object, arg);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
