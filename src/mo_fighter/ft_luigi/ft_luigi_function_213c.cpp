#pragma force_active on
// Deleting-destructor ABI: release storage only when the object is non-null and the flag is positive.
extern "C" void* fn_99_213C(void* object, short deleting) {
    if (object) {
        if (deleting > 0) operator delete(object);
    }
    return object;
}
