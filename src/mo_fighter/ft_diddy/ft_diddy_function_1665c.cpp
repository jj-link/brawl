#pragma force_active on
void operator delete(void*);
extern "C" void* fn_115_226C(void*, short);
extern "C" void* fn_115_2190(void*, short);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_115_1665C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_115_226C(storage + 0x50, -1);
        fn_115_2190(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
