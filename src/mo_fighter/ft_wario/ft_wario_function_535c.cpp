#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1CFC(void* member, short deleteFlag);
extern "C" void fn_110_53D4(void* object, short flag);

extern "C" void* fn_110_535C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1CFC((unsigned char*)object + 0x524, -1);
        if (object != 0) {
            fn_110_53D4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
