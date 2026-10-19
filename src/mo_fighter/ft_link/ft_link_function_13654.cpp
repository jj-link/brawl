#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_6394(void* object, short count);
extern "C" void* fn_93_62F8(void* object, short flag);

extern "C" void* fn_93_13654(void* object, short deleting) {
    short m1 = -1;
    if (object != 0) {
        fn_93_6394((char*)object + 0x50, m1);
        fn_93_62F8(object, m1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
