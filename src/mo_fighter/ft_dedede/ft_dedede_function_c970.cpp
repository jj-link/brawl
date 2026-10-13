void operator delete(void*);
extern "C" void* fn_117_C910(void*, short);

// The stop-energy pool subobject owns its holder at +8. Keep the rest opaque.
extern "C" void* fn_117_C970(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_C910(storage + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
