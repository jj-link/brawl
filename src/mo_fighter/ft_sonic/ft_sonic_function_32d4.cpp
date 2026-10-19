#pragma force_active on
extern "C" void fn_123_3330(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_32D4(void* object, short flag) {
    if (object != 0) {
        fn_123_3330(object, 0);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
