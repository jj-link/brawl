#pragma force_active on
extern "C" {
void fn_123_1F28(void*, short);
void* fn_123_1ECC(void*, short);
}

extern "C" void* fn_123_12C04(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = 0;
        fn_123_1F28(storage + 0x20, destroyMember);
        if (object) fn_123_1ECC(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
