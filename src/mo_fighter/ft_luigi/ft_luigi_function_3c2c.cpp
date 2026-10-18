#pragma force_active on
// Deleting-destructor ABI for a leaf object with no member teardown.
extern "C" void* fn_99_3C2C(void* object, short deleting) {
    if (object) {
        if (deleting > 0) operator delete(object);
    }
    return object;
}
