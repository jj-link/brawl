#pragma force_active on
extern "C" void fn_27_66114(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_6688(void* obj, short param) {
    if (obj != 0) {
        fn_27_66114(obj, -1);
        if (param > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
