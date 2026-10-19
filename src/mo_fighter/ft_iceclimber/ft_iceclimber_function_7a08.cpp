#pragma force_active on
extern "C" void fn_27_22A38(void*, short);
extern "C" void fn_27_1A2910(void*, short);
extern "C" void __dl__FPv(void*);

// Release the embedded member before the base, retaining their storage.
extern "C" void* fn_105_7A08(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_22A38(storage + 0x34, memberDeleting);
        fn_27_1A2910(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
