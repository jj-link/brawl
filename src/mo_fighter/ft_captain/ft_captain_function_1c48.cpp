#pragma force_active on
extern "C" void fn_100_1AD0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_1C48(void* object, short destroy) {
    if (object != 0) {
        fn_100_1AD0(object, 0);
        if (destroy > 0)
            __dl__FPv(object);
    }
    return object;
}
