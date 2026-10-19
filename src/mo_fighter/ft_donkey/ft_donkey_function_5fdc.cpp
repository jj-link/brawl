#pragma force_active on
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_92_6048(void*, short);
void operator delete(void*);

// Release the embedded member before the object itself, then free the storage.
extern "C" void* fn_92_5FDC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0x14, -1);
        fn_92_6048(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
