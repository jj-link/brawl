extern "C" void* fn_27_6880C(void*, short);

// Destroy the embedded member before optionally releasing the enclosing object.
extern "C" void* fn_99_FB68(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_6880C(storage + 4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
