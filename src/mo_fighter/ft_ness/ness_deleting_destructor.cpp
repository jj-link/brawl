// This callback owns no resources beyond its optional object allocation.
// The virtual table passes a signed-short deleting-destructor flag.
void operator delete(void*);

extern "C" void* fn_101_11614(void* object, short deleting) {
    if (object != 0 && deleting > 0) {
        operator delete(object);
    }
    return object;
}
