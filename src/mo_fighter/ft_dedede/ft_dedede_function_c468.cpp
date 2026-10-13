void operator delete(void*);
extern "C" void* fn_117_C408(void*, short);

// soInstancePoolSub's motion-energy holder begins eight bytes into the object.
// A negative inner destructor flag preserves the embedded storage.
extern "C" void* fn_117_C468(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_C408(storage + 8, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
