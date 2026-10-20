#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_105_68C4(void* object, short flag);

extern "C" void* fn_105_684C(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x318, -1);
        if (object != 0) {
            fn_105_68C4(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
