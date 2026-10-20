#pragma force_active on
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void* fn_97_6F00(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_97_6E88(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88((char*)object + 0xF0, -1);
        if (object != 0) {
            fn_97_6F00(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
