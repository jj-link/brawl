#pragma force_active on
extern "C" {
void* fn_99_A5E8(void*, short);
void* fn_99_A4B0(void*, short);
}

// Destroy the embedded module at 0x17c, then the object itself; only positive flags delete.
extern "C" void* fn_99_A648(void* object, short deleting) {
    if (object) {
        fn_99_A5E8(static_cast<unsigned char*>(object) + 0x17c, -1);
        if (object) {
            fn_99_A4B0(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
