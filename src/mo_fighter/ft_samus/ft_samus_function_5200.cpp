#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1CFC(void* member, short deleteFlag);
extern "C" void fn_94_5278(void* object, short flag);

extern "C" void* fn_94_5200(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1CFC((unsigned char*)object + 0x524, -1);
        if (object != 0) {
            fn_94_5278(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
