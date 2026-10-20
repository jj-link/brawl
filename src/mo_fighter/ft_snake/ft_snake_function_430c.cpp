#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void* fn_122_4394(void* p, short n);
extern "C" void* fn_122_43D4(void* object, short deleting);

extern "C" void* fn_122_430C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        if (storage + 0x24 != 0) {
            fn_27_1A262C(storage + 0x34, -1);
            fn_122_4394(storage + 0x24, 0);
        }
        fn_122_43D4(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
