#pragma force_active on
extern "C" void* fn_27_B64B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_2E60(void* object, short count) {
    if (object != 0) {
        fn_27_B64B8(object, -1);
        if (count > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
