#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_27_B81C4(void*, short);
void* fn_100_2D98(void*, short);
void* fn_27_198034(void*, short);
}

// Destroy the embedded modules in reverse construction order, then the base.
extern "C" void* fn_100_2D18(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroy = -1;
        fn_27_B81C4(storage + 0xA4, destroy);
        fn_100_2D98(storage + 0x48, destroy);
        if (object != 0) {
            fn_27_198034(object, destroy);
        }
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
