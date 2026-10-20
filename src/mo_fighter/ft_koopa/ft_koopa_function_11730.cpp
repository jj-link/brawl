#pragma force_active on
extern "C" {
void* fn_27_198E00(void*, short);
void* fn_27_199318(void*, short);
void* fn_27_A78FC(void*, short);
void* fn_27_A3704(void*, short);
}

extern "C" void* fn_102_11730(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = -1;
        fn_27_198E00(storage + 0xd8, destroyMember);
        fn_27_199318(storage + 0x6c, destroyMember);
        fn_27_A78FC(storage + 0x50, destroyMember);
        fn_27_A3704(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
