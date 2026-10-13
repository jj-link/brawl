void operator delete(void*);
extern "C" void* fn_117_C3A8(void*, short);

// The embedded base begins four bytes into the object. Its negative destructor
// flag preserves that storage; only a positive outer flag frees the allocation.
extern "C" void* fn_117_C408(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_C3A8(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
