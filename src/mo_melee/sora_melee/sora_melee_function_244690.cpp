#pragma force_active on
extern "C" void fn_27_2429BC(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_244690(void* obj, int arg2) {
    if (obj) {
        fn_27_2429BC(obj, 0);
        if (arg2 > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
