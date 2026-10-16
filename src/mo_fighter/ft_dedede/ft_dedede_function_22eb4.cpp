void operator delete(void*);

// Release the object's storage on a deleting destroy. The object is returned
// so destroy wrappers can forward it unchanged when the caller passes a null
// object or a non-deleting request (deleting <= 0).
extern "C" void* fn_117_22EB4(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
