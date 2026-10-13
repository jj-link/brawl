void operator delete(void*);
extern "C" void* fn_117_C58C(void*, short);

// The REL's RTTI identifies this as the gravity-energy holder destructor.
// Construction places its energy object at +4; the remaining layout is opaque.
extern "C" void* fn_117_C5E8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_C58C(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
