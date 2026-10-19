#pragma force_active on
extern "C" void fn_27_69684(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_5FB4(void* object, short flags) {
    if (object != 0) {
        fn_27_69684(object, -1);
        if (flags > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
