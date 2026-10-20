#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_119_3CF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_3C7C(void* object, short deleting) {
    if (object != 0) {
        short baseDeleting = -1;
        fn_27_1A15B8((char*)object + 0x470, baseDeleting);
        if (object != 0) {
            fn_119_3CF4(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
