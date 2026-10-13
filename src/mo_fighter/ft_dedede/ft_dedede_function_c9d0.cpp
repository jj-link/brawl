void operator delete(void*);
extern "C" void* fn_117_C970(void*, short);
extern "C" void* fn_117_C838(void*, short);

// The stop-energy pool subobject begins at +0xEC; the controller hierarchy
// remains at the receiver address. Keep the unneeded complete layout opaque.
extern "C" void* fn_117_C9D0(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_117_C970(static_cast<unsigned char*>(object) + 0xEC, memberDeleting);
        if (object != 0) {
            short baseDeleting = 0;
            fn_117_C838(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
