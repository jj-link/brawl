#pragma force_active on
extern "C" {
void* fn_97_2210(void*, short);
void* fn_97_22AC(void*, short);
void* fn_97_22EC(void*, short);
void* fn_27_C7770(void*, short);
}

extern "C" void* fn_97_27E4(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_97_2210((char*)object + 0xdc, memberDeleting);
        fn_97_22AC((char*)object + 0xc0, memberDeleting);
        fn_97_22EC((char*)object + 0x14, memberDeleting);
        if (object != 0) {
            fn_27_C7770(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
