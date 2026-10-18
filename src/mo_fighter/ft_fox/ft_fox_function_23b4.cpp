#pragma force_active on
extern "C" void* fn_27_1A09B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_23B4(void* object, short p2) {
    if (object != 0) {
        fn_27_1A09B4(object, -1);
        if (p2 > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
