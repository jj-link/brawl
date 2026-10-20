#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A1FE4(void*, short);
void* fn_101_7BA8(void*, short);
}

extern "C" void* fn_101_7B30(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1FE4(static_cast<unsigned char*>(object) + 0x244, static_cast<short>(-1));
        if (object != 0) {
            fn_101_7BA8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
