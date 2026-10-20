#pragma force_active on
extern "C" void fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_116_6014(void* object, short flag);
extern void operator delete(void*);

extern "C" void* fn_116_5F9C(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, -1);
        if (object != 0) {
            fn_116_6014(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
