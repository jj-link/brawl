#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_101_7EF0(void*, short);
}

extern "C" void* fn_101_7E78(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0xF0, static_cast<short>(-1));
        if (object != 0) {
            fn_101_7EF0(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
