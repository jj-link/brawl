#pragma force_active on
extern "C" void fn_97_57F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_5790(void* object, short deleting) {
    if (object != 0) {
        fn_97_57F0((char*)object + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
