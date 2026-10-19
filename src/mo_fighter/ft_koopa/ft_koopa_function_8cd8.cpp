#pragma force_active on
void operator delete(void*);
extern "C" void* fn_102_18F0(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

extern "C" void* fn_102_8CD8(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<unsigned char*>(object) + 0x1416C, static_cast<short>(-1));
        fn_102_18F0(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
