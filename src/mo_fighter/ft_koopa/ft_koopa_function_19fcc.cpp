#pragma force_active on
extern "C" void* fn_102_3A4C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_19FCC(void* obj, short param2) {
    if (obj) {
        fn_102_3A4C(obj, 0);
        if (param2 > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
