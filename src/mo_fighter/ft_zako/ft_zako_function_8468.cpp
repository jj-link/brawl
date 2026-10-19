#pragma force_active on
extern "C" void fn_126_7438(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_8468(void* object, int deleting) {
    if (object != 0) {
        fn_126_7438(object, 0);
        if ((short)deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
