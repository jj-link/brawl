#pragma force_active on
// Deleting-destructor ABI: release storage only when the object exists and the delete flag is positive.
extern "C" void* fn_99_3CC8(void* object, short deleting) {
    if (object) {
        if (deleting > 0) operator delete(object);
    }
    return object;
}
