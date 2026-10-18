#pragma force_active on
extern "C" void fn_27_1A736C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_7ED0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A736C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
