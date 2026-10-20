#pragma force_active on
extern "C" {
void* fn_99_3E8C(void*, short);
void* fn_99_45C4(void*, short);
void* fn_27_19E99C(void*, short);
}

// Destroy embedded members, then optionally the object itself.
extern "C" void* fn_99_454C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_99_3E8C(storage + 0x85C, destroyMember);
        fn_99_45C4(storage + 0x19C, destroyMember);
        fn_27_19E99C(object, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
