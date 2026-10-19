#pragma force_active on
extern "C" void* fn_119_AE48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_AFE0(void* object, short flag) {
    if (object != 0) {
        short base = 0;
        fn_119_AE48(object, base);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
