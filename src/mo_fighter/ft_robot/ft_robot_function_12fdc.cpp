#pragma force_active on
extern "C" void* fn_27_C31CC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_120_12FDC(void* object, short flag) {
    if (object) {
        fn_27_C31CC(object, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
