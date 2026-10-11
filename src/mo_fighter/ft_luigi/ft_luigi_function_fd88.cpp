extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_99_FE00(void*, short);
}

// Destroy embedded members in reverse order, then the base subobject.
extern "C" void* fn_99_FD88(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_13C90(storage + 0x9c, destroyMember);
        fn_27_21038(storage + 0x88, destroyMember);
        fn_99_FE00(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
