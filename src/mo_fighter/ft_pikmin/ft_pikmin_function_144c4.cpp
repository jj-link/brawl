#pragma force_active on
extern "C" void* fn_113_14534(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

void operator delete(void*);

extern "C" void* fn_113_144C4(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate before the non-deleting base form.
        fn_113_14534(static_cast<unsigned char*>(object) + 0xCC, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
