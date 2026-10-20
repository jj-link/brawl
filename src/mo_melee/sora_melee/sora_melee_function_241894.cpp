#pragma force_active on
extern "C" void fn_27_24145C(void* a, int b);
extern "C" void __dl__FPv(void* a);

extern "C" void* fn_27_241894(void* obj, int release) {
    if (obj) {
        fn_27_24145C(obj, 0);
        if (release > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
