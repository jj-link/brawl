#pragma force_active on
extern "C" {
void* fn_27_1A15B8(void*, short);
void fn_99_4804(void*, short);
}

// Destroy the embedded module at 0x470 before the base; only positive flags delete.
extern "C" void* fn_99_478C(void* object, short deleting) {
    if (object) {
        fn_27_1A15B8(static_cast<unsigned char*>(object) + 0x470, -1);
        if (object) {
            fn_99_4804(object, 0);
        }
        if (deleting > 0) operator delete(object);
    }
    return object;
}
