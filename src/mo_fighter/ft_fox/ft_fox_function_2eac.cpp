#pragma force_active on
extern "C" void* fn_27_B64B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_2EAC(void* object, short size) {
    if (object != 0) {
        fn_27_B64B8(object, -1);
        if (size > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
