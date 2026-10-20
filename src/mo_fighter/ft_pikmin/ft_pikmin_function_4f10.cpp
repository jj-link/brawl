#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void fn_113_4F88(void* object, short flag);

extern "C" void* fn_113_4F10(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x218, -1);
        if (object != 0) {
            fn_113_4F88(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
