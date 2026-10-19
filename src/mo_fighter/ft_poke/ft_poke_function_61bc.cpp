#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_6228(void*, short);
extern "C" void* fn_116_3E50(void*, short);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_116_61BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_6228(storage + 0x24, -1);
        fn_116_3E50(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
