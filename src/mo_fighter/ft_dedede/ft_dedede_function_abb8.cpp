void operator delete(void*);

extern "C" void* fn_117_D09C(void*, short);

extern "C" void* fn_117_ABB8(void* object, short deleting) {
    if (object != 0) {
        // The enclosing destructor passes this subobject at +0xE0; its member
        // destructor starts four bytes later and must not free embedded storage.
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_117_D09C(members + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
