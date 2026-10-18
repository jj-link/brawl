#pragma force_active on
extern "C" void* fn_27_14FCF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_2FF0(void* object, short p2) {
    if (object != 0) {
        fn_27_14FCF4(object, -1);
        if (p2 > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
