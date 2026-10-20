#pragma force_active on
extern "C" {
void* fn_99_A910(void*, short);
void* fn_99_A7DC(void*, short);
}

// Destroy the embedded module at 0x204, then the base; only positive flags delete.
extern "C" void* fn_99_A970(void* object, short deleting) {
    if (object) {
        fn_99_A910(static_cast<unsigned char*>(object) + 0x204, -1);
        if (object) {
            fn_99_A7DC(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
