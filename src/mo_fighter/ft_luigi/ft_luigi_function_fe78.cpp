extern "C" void* fn_99_FED4(void*, short);

// Destroy the embedded module without releasing it, then honor the deleting flag.
extern "C" void* fn_99_FE78(void* object, short deleting) {
    if (object) {
        int destroyMember = 0;
        fn_99_FED4(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
