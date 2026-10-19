#pragma force_active on
extern "C" {
void fn_27_1A20EC(void*, short);
void* fn_91_5830(void*, short);
}

extern "C" void* fn_91_57C0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A20EC(static_cast<unsigned char*>(object) + 0x10, static_cast<short>(-1));
        fn_91_5830(object, static_cast<short>(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
