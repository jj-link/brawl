#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_116_2164(void*, short);
void* fn_116_2200(void*, short);
void* fn_116_2240(void*, short);
void* fn_116_285C(void*, short);
void* fn_27_1A5AC4(void*, short);
}

extern "C" void* fn_116_27C4(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_116_2164(static_cast<unsigned char*>(object) + 0x9AC, memberDeleting);
        fn_116_2200(static_cast<unsigned char*>(object) + 0x990, memberDeleting);
        fn_116_2240(static_cast<unsigned char*>(object) + 0x8E4, memberDeleting);
        fn_116_285C(static_cast<unsigned char*>(object) + 0x470, memberDeleting);
        if (object != 0) {
            fn_27_1A5AC4(object, memberDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
