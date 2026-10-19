#pragma force_active on
extern "C" void* fn_97_4C84(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_D400(void* object, short deleting) {
    if (object != 0) {
        fn_97_4C84(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
