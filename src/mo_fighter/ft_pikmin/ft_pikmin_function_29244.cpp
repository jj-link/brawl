#pragma force_active on
extern "C" void fn_113_2F3C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_29244(void* object, short deleting) {
    if (object != 0) {
        fn_113_2F3C((char*)object + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
