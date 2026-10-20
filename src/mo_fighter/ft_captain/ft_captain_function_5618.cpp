#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_100_5690(void*, short);

extern "C" void* fn_100_5618(char* object, short baseDeleting) {
    if (object != 0) {
        fn_27_1A15B8(object + 0x1fc, -1);
        if (object != 0) {
            fn_100_5690(object, 0);
        }
        if (baseDeleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
