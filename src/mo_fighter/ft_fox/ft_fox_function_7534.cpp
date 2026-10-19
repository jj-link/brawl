#pragma force_active on
extern "C" void fn_27_69684(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_7534(void* object, short deleting) {
    void* ret = object;
    if (object != 0) {
        fn_27_69684(object, (short)-1);
        if (deleting > 0) {
            __dl__FPv(object);
            ret = object;
        }
    }
    return ret;
}
