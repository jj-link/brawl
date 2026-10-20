#pragma force_active on
extern "C" void fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_125_6EA0(void* object, short flag);

void operator delete(void*);

extern "C" void* fn_125_6E28(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, -1);
        if (object != 0) {
            fn_125_6EA0(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
