#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void* fn_99_4CB4(void*, short);
}

void operator delete(void*);

// Destroy the member owned at 0x138, then the embedded base, then the block itself.
extern "C" void* fn_99_4C3C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_1A15B8(storage + 0x138, destroyMember);
        if (object) {
            int destroyBase = 0;
            fn_99_4CB4(object, destroyBase);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
