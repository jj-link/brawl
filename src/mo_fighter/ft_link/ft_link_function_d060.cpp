#pragma force_active on
void operator delete(void*);
extern "C" void* fn_93_D000(void*, short);
extern "C" void* fn_93_CEE0(void*, short);

extern "C" void* fn_93_D060(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded member before the non-deleting base form.
        fn_93_D000(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_93_CEE0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
