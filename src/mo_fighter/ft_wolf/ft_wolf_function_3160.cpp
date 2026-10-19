#pragma force_active on
extern "C" void* fn_27_A0C34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_3160(void* obj, short flags) {
    if (obj != 0) {
        fn_27_A0C34(obj, -1);
        if (flags > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
