#pragma force_active on
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_101_79C8(void*, short);
void operator delete(void*);

extern "C" void* fn_101_7950(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A18A0(static_cast<unsigned char*>(object) + 0x354, static_cast<short>(-1));
        if (object != 0) {
            fn_101_79C8(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
