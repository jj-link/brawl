#pragma force_active on
extern "C" {
void* fn_27_1A1B88(void*, short);
void* fn_99_4E94(void*, short);
void __dl__FPv(void*);
}

// Destroy the member owned at +0x88, then the enclosing base itself.
// Only positive flags release the memory; the object pointer is always returned.
extern "C" void* fn_99_4E1C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_1A1B88(storage + 0x88, destroyMember);
        if (object) {
            int destroyBase = 0;
            fn_99_4E94(object, destroyBase);
        }
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
