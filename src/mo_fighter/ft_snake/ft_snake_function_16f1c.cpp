#pragma force_active on
void operator delete(void*);
extern "C" void* fn_122_16F8C(void*, short);
extern "C" void* fn_122_1724C(void*, short);

extern "C" void* fn_122_16F1C(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate before the non-deleting base form.
        fn_122_16F8C(static_cast<unsigned char*>(object) + 0x1CE4, -1);
        fn_122_1724C(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
