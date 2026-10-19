#pragma force_active on
extern "C" void* fn_112_1FA8(void*, short);
extern "C" void* fn_112_4848(void*, short);
void operator delete(void*);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_112_58EC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_112_1FA8(storage + 0x20, 0);
        fn_112_4848(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
