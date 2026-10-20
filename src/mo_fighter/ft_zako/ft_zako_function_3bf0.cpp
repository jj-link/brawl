#pragma force_active on
extern "C" void* fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_126_3C68(void* object, short deleting);

extern "C" void* fn_126_3BF0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0xB4, -1);
        if (object != 0) {
            fn_126_3C68(object, 0);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
