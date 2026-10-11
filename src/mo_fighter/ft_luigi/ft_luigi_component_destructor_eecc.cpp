extern "C" void* fn_99_21BC(void*, short);
extern "C" void* fn_99_20E0(void*, short);

extern "C" void* fn_99_EECC(void* object, short deleting) {
    if (object) {
        // Destroy the embedded component before its interpreter base.
        short destroyComponent = -1;
        fn_99_21BC(static_cast<unsigned char*>(object) + 0x50, destroyComponent);
        fn_99_20E0(object, destroyComponent);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
