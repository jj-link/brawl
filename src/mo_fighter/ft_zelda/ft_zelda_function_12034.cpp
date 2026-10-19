#pragma force_active on
extern "C" void* fn_104_4618(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_12034(void* object, int flags) {
    if (object != 0) {
        fn_104_4618(object, 0);
        if ((short)flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
