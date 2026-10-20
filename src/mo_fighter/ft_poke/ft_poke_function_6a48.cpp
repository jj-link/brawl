#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_116_6AC0(void* object, short deleting);
void* fn_116_6B20(void* object, short baseDeleting);
}

extern "C" void* fn_116_6A48(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_116_6AC0(storage + 0x18, destroyMember);
        fn_116_6B20(storage + 0x4, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
