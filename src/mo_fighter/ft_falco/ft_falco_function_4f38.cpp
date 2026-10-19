#pragma force_active on
extern "C" {
void* fn_27_25740(void*, short);
void* fn_27_CC0F0(void*, short);
}

void operator delete(void*);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_108_4F38(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_25740(storage + 0x50, -1);
        fn_27_CC0F0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
