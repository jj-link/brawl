// Deleting-destructor ABI for a leaf object with no member teardown.
extern "C" void* fn_99_1029C(void* object, short deleting) {
    if (object && deleting > 0) {
        operator delete(object);
    }
    return object;
}
