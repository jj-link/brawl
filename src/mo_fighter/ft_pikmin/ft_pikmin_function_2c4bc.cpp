#pragma force_active on
void operator delete(void*);
extern "C" void* fn_113_2C52C(void*, short);
extern "C" void* fn_113_2C7EC(void*, short);

extern "C" void* fn_113_2C4BC(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate before the non-deleting base form.
        fn_113_2C52C(static_cast<unsigned char*>(object) + 0x1808, -1);
        fn_113_2C7EC(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
