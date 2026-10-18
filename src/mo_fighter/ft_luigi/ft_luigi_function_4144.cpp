#pragma force_active on
// Deleting-destructor ABI for a leaf object with no member teardown.
extern "C" void* fn_99_4144(void* object, short deleting) {
    if (object) {
        if (deleting > 0) operator delete(object);
    }
    return object;
}
