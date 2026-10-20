#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_D2904(void*, short);
void* fn_101_7A40(void*, short);
}

extern "C" void* fn_101_79C8(void* object, short deleting) {
    if (object != 0) {
        fn_27_D2904(static_cast<unsigned char*>(object) + 0x318, static_cast<short>(-1));
        if (object != 0) {
            fn_101_7A40(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
