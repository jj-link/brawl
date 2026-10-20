#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A1E70(void* object, short value);
extern "C" void fn_110_58FC(void* object, short deleting);

extern "C" void* fn_110_5884(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70((char*)object + 0x190, -1);
        if (object != 0) {
            fn_110_58FC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
