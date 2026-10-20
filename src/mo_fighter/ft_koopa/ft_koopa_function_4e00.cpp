#pragma force_active on
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void* fn_102_4E78(void* object, short deleteFlag);
extern "C" void operator delete(void*);

extern "C" void* fn_102_4E00(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0xB4, -1);
        if (object != 0) {
            fn_102_4E78(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
