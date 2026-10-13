void operator delete(void*);
extern "C" void* fn_117_C718(void*, short);

// The controller-energy holder's owned storage starts four bytes into the object.
// The negative inner destructor flag leaves that embedded storage allocated.
extern "C" void* fn_117_C778(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_117_C718(storage + 4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
