#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_104_21D0(void*, short);
void* fn_104_226C(void*, short);
void* fn_104_22AC(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_104_24E8(void* object, short deleting) {
    if (object != 0) {
        fn_104_21D0((unsigned char*)object + 0xDC, -1);
        fn_104_226C((unsigned char*)object + 0xC0, -1);
        fn_104_22AC((unsigned char*)object + 0x14, -1);
        if (object != 0) {
            fn_27_C7770(object, -1);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
