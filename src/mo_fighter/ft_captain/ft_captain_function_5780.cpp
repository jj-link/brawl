#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void fn_100_57F8(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_100_5780(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8((char*)object + 0x138, -1);
        if (object != 0) {
            fn_100_57F8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
