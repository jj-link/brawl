#pragma force_active on
extern "C" void* fn_27_19816C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_2DF4(void* object, short count) {
    if (object != 0) {
        fn_27_19816C(object, static_cast<short>(-1));
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
