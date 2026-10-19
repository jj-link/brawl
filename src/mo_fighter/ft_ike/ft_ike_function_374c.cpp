#pragma force_active on
extern "C" {
void* fn_119_1F88(void* ptr, short flag);
void* fn_119_1F2C(void* ptr, short flag);
}

extern "C" void* fn_119_374C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = 0;
        fn_119_1F88(storage + 0x20, destroyMember);
        if (object) fn_119_1F2C(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
