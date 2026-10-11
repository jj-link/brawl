extern "C" void* fn_27_1A262C(void*, short);

// Destroy the embedded member before optionally releasing its owner.
extern "C" void* fn_99_F994(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_27_1A262C(static_cast<unsigned char*>(object) + 0x10, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
