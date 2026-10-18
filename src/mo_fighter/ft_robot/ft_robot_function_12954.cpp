#pragma force_active on
extern "C" void* fn_27_1A262C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_12954(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_1A262C(storage + 0x10, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
