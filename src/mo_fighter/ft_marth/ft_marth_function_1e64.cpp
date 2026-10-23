#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void* fn_106_1EE4(void*, short);
void* fn_106_1F40(void*, short);
}

// Destroy the Marth storage: release the embedded subobject at +0x20 when
// present, the embedded helpers at +0x14 and +8, and the storage itself when
// a delete was requested, preserving the original pointer either way.
extern "C" void* fn_106_1E64(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        short zero = 0;
        fn_106_1EE4(storage + 0x14, zero);
        fn_106_1F40(storage + 8, zero);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
