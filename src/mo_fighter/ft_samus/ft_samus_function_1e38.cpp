#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void* fn_94_1EB8(void*, short);
void fn_94_1F14(void*, short);
}

// Destroy the Samus storage: release the sub-object at +0x20 when present,
// the embedded helpers at +0x14 and +8, and the storage itself when a delete
// was requested, returning the original pointer either way.
extern "C" void* fn_94_1E38(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_94_1EB8(storage + 0x14, 0);
        fn_94_1F14(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
