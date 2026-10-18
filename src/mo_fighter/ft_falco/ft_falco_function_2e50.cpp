#pragma force_active on
extern "C" void* fn_27_B64B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_108_2E50(void* object, short flag) {
    if (object != 0) {
        fn_27_B64B8(object, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
