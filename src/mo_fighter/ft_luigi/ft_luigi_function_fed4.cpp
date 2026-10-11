extern "C" void* fn_27_D2AA4(void*, short);

// Destroy the embedded module, then honor the signed deleting flag.
extern "C" void* fn_99_FED4(void* object, short deleting) {
    if (object) {
        if (object) {
            int destroyMember = -1;
            fn_27_D2AA4(object, destroyMember);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
