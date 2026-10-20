#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_117_4EB4(void* object, short deleting);

extern "C" void* fn_117_4E3C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x218, static_cast<short>(-1));
        if (object != 0) {
            fn_117_4EB4(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
