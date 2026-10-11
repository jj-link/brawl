// Input and IpNull own no resources beyond their object allocation.
// The existing virtual tables pass a signed-short deleting-destructor flag.
void operator delete(void*);

extern "C" void* fn_118_13AE4(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}

extern "C" void* fn_118_13B24(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
