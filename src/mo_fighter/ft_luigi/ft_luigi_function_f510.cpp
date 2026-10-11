extern "C" {
void* fn_99_F588(void*, short);
void* fn_99_F5C8(void*, short);
void* fn_99_F628(void*, short);
}

// Destroy the embedded modules owned by this layer, then optionally the layer itself.
extern "C" void* fn_99_F510(void* object, short deleting) {
    if (object) {
        int destroyMember = -1;
        fn_99_F588(static_cast<unsigned char*>(object) + 0xB0, destroyMember);
        fn_99_F5C8(static_cast<unsigned char*>(object) + 0x30, destroyMember);
        fn_99_F628(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
