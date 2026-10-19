#pragma force_active on
extern "C" void* fn_116_3844(void* ptr, short flag);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_C77C(void* obj, short param) {
    if (obj != 0) {
        fn_116_3844(obj, 0);
        if (param > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
