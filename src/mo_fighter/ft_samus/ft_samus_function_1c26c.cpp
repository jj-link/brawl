#pragma force_active on
void operator delete(void*);
extern "C" void* fn_94_1C2DC(void*, short);
extern "C" void* fn_27_1D81C8(void*, short);

extern "C" void* fn_94_1C26C(void* object, short deleting) {
    if (object != 0) {
        // Destroy the embedded aggregate before the non-deleting base form.
        fn_94_1C2DC(static_cast<unsigned char*>(object) + 0xCC, -1);
        fn_27_1D81C8(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
