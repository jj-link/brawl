extern "C" void* fn_99_3C6C(void*, short);

// Destroy the embedded module before optionally releasing its owner.
extern "C" void* fn_99_F8C8(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_99_3C6C(static_cast<unsigned char*>(object) + 0x14, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
