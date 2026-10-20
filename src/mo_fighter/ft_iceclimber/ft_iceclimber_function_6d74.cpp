#pragma force_active on
extern "C" void fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_105_6DEC(void* object, short flag);

void operator delete(void*);

extern "C" void* fn_105_6D74(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xb4, -1);
        if (object != 0) {
            fn_105_6DEC(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
