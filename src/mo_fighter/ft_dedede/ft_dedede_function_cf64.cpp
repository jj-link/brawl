void operator delete(void*);
extern "C" void* fn_117_CF08(void*, short);

// The REL's RTTI identifies this as the jostle-energy holder.
// Its embedded energy starts at +4 and must not free the holder's storage.
extern "C" void* fn_117_CF64(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_CF08(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
