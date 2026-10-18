#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void fn_107_1FF4(void*, short);
void fn_107_2050(void*, short);
}

// Destroy the gamewatch storage: release the subobject at +0x20 when
// present, the embedded helpers at +0x14 and +8, and the storage itself when
// a delete was requested, preserving the original pointer either way.
extern "C" void* fn_107_1F74(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_107_1FF4(storage + 0x14, 0);
        fn_107_2050(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
