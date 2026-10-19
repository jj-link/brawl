#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_120_4D10(void* p, short flag);

// Release the embedded member at +0x14 and the object itself, then
// optionally free the storage when the deleting flag is positive.
extern "C" void* fn_120_4CA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0x14, -1);
        fn_120_4D10(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
