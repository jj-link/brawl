#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_1A20EC(void*, short);
void* fn_101_3F84(void*, short);
}

extern "C" void* fn_101_74C4(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, static_cast<short>(-1));
        fn_101_3F84(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
