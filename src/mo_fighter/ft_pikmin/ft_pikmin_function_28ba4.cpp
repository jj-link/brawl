#pragma force_active on
extern "C" void* fn_113_2948(void*, short);
extern "C" void* fn_113_28C34(void*, short);
extern "C" void* fn_113_28CC0(void*, short);
extern "C" void* fn_113_28D4C(void*, short);
extern "C" void* fn_113_28DD8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_28BA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_113_2948(storage + 0x4B0, -1);
        fn_113_28C34(storage + 0x384, -1);
        fn_113_28CC0(storage + 0x258, -1);
        fn_113_28D4C(storage + 0x12C, -1);
        fn_113_28DD8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
