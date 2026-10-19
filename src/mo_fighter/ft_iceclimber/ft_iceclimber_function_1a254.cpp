#pragma force_active on
void operator delete(void*);
extern "C" void* fn_105_1A2C4(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_105_1A254(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded member object first, then the non-deleting base form.
        fn_105_1A2C4(static_cast<unsigned char*>(object) + 0xcc, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
