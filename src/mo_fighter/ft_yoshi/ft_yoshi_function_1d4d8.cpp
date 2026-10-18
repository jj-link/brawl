#pragma force_active on
extern "C" void* fn_95_3EE8(void*, short);
extern "C" void* fn_95_3F6C(void*, short);
extern "C" void* fn_95_1D574(void*, short);
extern "C" void* fn_95_3FCC(void*, short);
extern "C" void* fn_95_40F4(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_95_1D4D8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_95_3EE8(storage + 0x118, -1);
        fn_95_3F6C(storage + 0x104, -1);
        fn_95_1D574(storage + 0xec, -1);
        fn_95_3FCC(storage + 0x48, -1);
        fn_95_40F4(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
