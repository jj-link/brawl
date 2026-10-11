extern "C" {
void* fn_99_3DA8(void*, short);
void* fn_99_3E2C(void*, short);
void* fn_99_F738(void*, short);
void* fn_99_F794(void*, short);
void* fn_99_F8C8(void*, short);
void* fn_27_C74E8(void*, short);
}

// Destroy embedded modules in reverse order before the base subobject.
// A positive signed deletion flag also releases the enclosing allocation.
extern "C" void* fn_99_F69C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_99_3DA8(storage + 0x114, destroyMember);
        fn_99_3E2C(storage + 0x100, destroyMember);
        fn_99_F738(storage + 0xec, destroyMember);
        fn_99_F794(storage + 0x48, destroyMember);
        fn_99_F8C8(storage + 0x10, destroyMember);
        fn_27_C74E8(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
