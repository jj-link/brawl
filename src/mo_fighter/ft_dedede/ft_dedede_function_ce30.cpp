void operator delete(void*);
extern "C" void* fn_117_CDD0(void*, short);

// Destroy the embedded lifetime object at +8 without deleting its storage.
// The containing object's remaining layout is not needed by this destructor.
extern "C" void* fn_117_CE30(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_CDD0(storage + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
