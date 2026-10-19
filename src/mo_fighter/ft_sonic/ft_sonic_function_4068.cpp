#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_1ECC(void*, short);
extern "C" void fn_123_1F28(void*, short);

extern "C" void* fn_123_4068(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_123_1ECC(storage + 0x14, 0);
        fn_123_1F28(storage + 0x8, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
