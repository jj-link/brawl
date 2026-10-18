#pragma force_active on
extern "C" void* fn_27_A0C74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_22E0(void* object, short flag) {
    if (object != 0) {
        fn_27_A0C74(object, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
