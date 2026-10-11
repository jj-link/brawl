// These callbacks own no resources beyond their optional object allocation.
// Existing virtual tables pass a signed-short deleting-destructor flag.
void operator delete(void*);

extern "C" void* fn_101_15D6C(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_101_15DAC(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
