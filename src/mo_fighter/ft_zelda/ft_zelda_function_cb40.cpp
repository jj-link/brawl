#pragma force_active on
void operator delete(void*);
extern "C" void* fn_104_CAE0(void* object, short deleting);
extern "C" void fn_104_C9AC(void* object, short deleting);

extern "C" void* fn_104_CB40(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        fn_104_CAE0((unsigned char*)object + 0x1C8, flag);
        if (object != 0) {
            short zero = 0;
            fn_104_C9AC(object, zero);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
