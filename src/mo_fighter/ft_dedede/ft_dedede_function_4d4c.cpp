#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A1B88(void*, short);
extern "C" void fn_117_4DC4(void*, short);

extern "C" void* fn_117_4D4C(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x2D0, static_cast<short>(-1));
        if (object != 0) {
            fn_117_4DC4(object, static_cast<short>(0));
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
