void operator delete(void*);

// Empty base destructor; the signed ABI flag controls deletion of the object.
extern "C" void* fn_117_A614(void* object, short deleting) {
    if (object != 0) {
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
