#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void fn_116_5EAC(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_116_5E34(char* object, short baseDeleting) {
    if (object != 0) {
        fn_27_1A15B8(object + 0x138, -1);
        if (object != 0) {
            fn_116_5EAC(object, 0);
        }
        if (baseDeleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
