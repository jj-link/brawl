#pragma force_active on
extern "C" void* fn_27_19874C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_6CC0(void* object, short flag) {
    if (object != 0) {
        fn_27_19874C(object, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
