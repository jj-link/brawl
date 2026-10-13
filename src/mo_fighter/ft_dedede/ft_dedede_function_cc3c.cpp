void operator delete(void*);
extern "C" void* fn_117_CBDC(void*, short);

// The wind-energy holder stores its embedded energy four bytes into the object.
// A negative inner destructor flag preserves the embedded storage.
extern "C" void* fn_117_CC3C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_CBDC(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
