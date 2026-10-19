#pragma force_active on
extern "C" void* fn_27_14B698(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_5F30(void* obj, short val) {
    if (obj) {
        fn_27_14B698(obj, -1);
        if (val > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
