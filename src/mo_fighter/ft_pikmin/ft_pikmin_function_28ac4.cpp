#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_28B34(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_113_28AC4(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate at +0xCC before the non-deleting base form.
        fn_113_28B34(static_cast<unsigned char*>(object) + 0xcc, static_cast<short>(-1));
        fn_27_1D81C8(object, static_cast<short>(0));
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
