#pragma force_active on
extern "C" void fn_116_4BC4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_4B64(void* object, short deleting) {
    if (object != 0) {
        fn_116_4BC4((char*)object + 12, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
