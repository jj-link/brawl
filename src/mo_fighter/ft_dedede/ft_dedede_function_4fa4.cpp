#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void* fn_117_501C(void* object, short deleting);

extern "C" void* fn_117_4FA4(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x154, static_cast<short>(-1));
        if (object != 0) {
            fn_117_501C(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
