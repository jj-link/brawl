void operator delete(void*);
extern "C" void* fn_117_A614(void*, short);

// The wind-energy holder destroys this embedded energy through its base.
// Keep the receiver opaque; this wrapper does not access the energy's fields.
extern "C" void* fn_117_CBDC(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short baseDeleting = 0;
            fn_117_A614(object, baseDeleting);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
