#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_101_5F1C(void*, short);
void* fn_101_6440(void*, short);
}

extern "C" void* fn_101_63D0(void* object, short deleting) {
    if (object != 0) {
        fn_101_5F1C(static_cast<unsigned char*>(object) + 0x13510, static_cast<short>(-1));
        fn_101_6440(static_cast<unsigned char*>(object) + 0x4, static_cast<short>(-1));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
