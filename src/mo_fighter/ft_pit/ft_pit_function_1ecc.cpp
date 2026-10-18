#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void fn_112_1F4C(void*, short);
void fn_112_1FA8(void*, short);
}

// Destroy the ft_pit storage: release the sora_melee subobject at +0x20 when
// present, the embedded helpers at +0x14 and +8, and the storage itself when
// a delete was requested, preserving the original pointer either way.
extern "C" void* fn_112_1ECC(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_112_1F4C(storage + 0x14, 0);
        fn_112_1FA8(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
