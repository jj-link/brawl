#pragma force_active on
extern "C" void* fn_27_1A4980(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_EBC4(void* object, short flag) {
    if (object != 0) {
        fn_27_1A4980(object, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
