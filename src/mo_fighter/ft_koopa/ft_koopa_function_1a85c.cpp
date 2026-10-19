#pragma force_active on
extern "C" {
void fn_102_1EE8(void*, short);
void fn_102_1E8C(void*, short);
}

extern "C" void* fn_102_1A85C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = 0;
        fn_102_1EE8(storage + 0x20, destroyMember);
        if (object) fn_102_1E8C(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
