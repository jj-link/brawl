#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void fn_110_56A4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_110_562C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8((char*)object + 0x2fc, -1);
        if (object != 0) {
            fn_110_56A4(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
