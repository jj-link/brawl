void operator delete(void*);
extern "C" void* fn_117_CA48(void*, short);

// Destroy the damage-energy holder's embedded storage without freeing it.
extern "C" void* fn_117_CAA4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_CA48(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
