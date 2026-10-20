#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_123_6620(void*, short);
void* fn_123_6680(void*, short);
}

extern "C" void* fn_123_65A8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_123_6620(storage + 0x18, destroyMember);
        fn_123_6680(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
