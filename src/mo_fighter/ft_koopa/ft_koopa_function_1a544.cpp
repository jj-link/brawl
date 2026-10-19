#pragma force_active on
extern "C" {
extern void* fn_27_C31CC(void*, short);
extern void __dl__FPv(void*);

void* fn_102_1A544(void* obj, short val) {
    if (obj != 0) {
        fn_27_C31CC(obj, -1);
        if (val > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}
