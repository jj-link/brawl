#pragma force_active on
extern "C" void* fn_27_A0C34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_3164(void* object, short p2) {
    if (object) {
        fn_27_A0C34(object, -1);
        if (p2 > 0)
            __dl__FPv(object);
    }
    return object;
}
