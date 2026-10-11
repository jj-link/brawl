// This base has no owned members; only a positive signed deletion flag
// releases its allocation. The destructor returns the original object.
extern "C" void* fn_99_FB28(void* object, short deleting) {
    if (object) {
        if (deleting > 0) operator delete(object);
    }
    return object;
}
