#pragma force_active on
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_105_69B4(void* object, short flag);
void operator delete(void*);

extern "C" void* fn_105_693C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2d0, -1);
        if (object != 0) {
            fn_105_69B4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
