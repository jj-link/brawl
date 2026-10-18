#pragma force_active on
void operator delete(void*);

// Deleting-destructor style callback: frees the object when non-null and the
// signed-short deleting flag is positive, then returns the object pointer.
extern "C" void* fn_101_2434(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
