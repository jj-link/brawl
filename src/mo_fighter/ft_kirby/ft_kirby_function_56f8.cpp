#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_96_5680(void*, short);

extern "C" void* fn_96_56F8(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8((unsigned char*)object + 0x470, -1);
        if (object != 0) {
            fn_96_5680(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
