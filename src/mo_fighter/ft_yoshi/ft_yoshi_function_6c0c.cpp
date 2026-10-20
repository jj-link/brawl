#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void* fn_95_6C84(void*, short);
void operator delete(void*);

extern "C" void* fn_95_6C0C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A15B8((unsigned char*)object + 0x11C, -1);
        if (object != 0) {
            fn_95_6C84(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
