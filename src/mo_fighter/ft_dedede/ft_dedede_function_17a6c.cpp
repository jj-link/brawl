void operator delete(void*);

// Destroy the object when both the pointer and the delete request are valid,
// preserving the original pointer either way.
extern "C" void* fn_117_17A6C(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
