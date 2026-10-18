#pragma force_active on
extern "C" void* fn_27_14FCF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_2FB8(void* object, short flag) {
    if (object != 0) {
        fn_27_14FCF4(object, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
