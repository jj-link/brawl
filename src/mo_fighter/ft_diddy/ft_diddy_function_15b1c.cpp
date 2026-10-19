#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_115_15ADC(void*, short);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_115_15B1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0xC, -1);
        fn_115_15ADC(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
