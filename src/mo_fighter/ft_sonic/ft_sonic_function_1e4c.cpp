#pragma force_active on
void operator delete(void*);
extern "C" {
void fn_27_57BA0(void*, short);
void* fn_123_1ECC(void*, short);
void fn_123_1F28(void*, short);
}

extern "C" void* fn_123_1E4C(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        if (storage + 0x20 != 0) {
            fn_27_57BA0(storage + 0x20, 0);
        }
        fn_123_1ECC(storage + 0x14, 0);
        fn_123_1F28(storage + 8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
