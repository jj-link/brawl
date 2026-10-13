void operator delete(void*);
extern "C" void* fn_117_C5E8(void*, short);

// The REL's gravity-pool-sub RTTI points to this lifetime operation.
// It tears down the holder at +8; the receiver's full layout remains opaque.
extern "C" void* fn_117_C648(void* object, short deleting) {
    if (object != 0) {
        fn_117_C5E8(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
