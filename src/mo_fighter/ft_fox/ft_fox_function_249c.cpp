#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_97_2210(void*, short);
void* fn_97_22AC(void*, short);
void* fn_97_22EC(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_97_249C(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_97_2210((unsigned char*)object + 0xDC, memberDeleting);
        fn_97_22AC((unsigned char*)object + 0xC0, memberDeleting);
        fn_97_22EC((unsigned char*)object + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
