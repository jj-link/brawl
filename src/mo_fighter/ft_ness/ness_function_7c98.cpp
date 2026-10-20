#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_1A1E70(void*, short);
void fn_101_7D10(void*, short);
}

extern "C" void* fn_101_7C98(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<unsigned char*>(object) + 0x190, static_cast<short>(-1));
        if (object != 0) {
            fn_101_7D10(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
