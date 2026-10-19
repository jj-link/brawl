#pragma force_active on
extern "C" void* fn_115_15C50(void*, short);
extern "C" void* fn_115_3C8C(void*, short);
void operator delete(void*);

// Release the embedded members before the object itself, retaining storage.
extern "C" void* fn_115_15CB0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_115_15C50(storage + 0x24, memberDeleting);
        fn_115_3C8C(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
