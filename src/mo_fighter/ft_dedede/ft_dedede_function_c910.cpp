void operator delete(void*);
extern "C" void* fn_117_C8B0(void*, short);

// The REL's RTTI identifies this as the stop-energy holder destructor.
// Construction places its energy object at +4; the remaining layout is opaque.
extern "C" void* fn_117_C910(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_C8B0(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
