#pragma force_active on
extern "C" {
void* fn_27_B5324(void*, short);
void* fn_119_4EE8(void*, short);
void* fn_119_4F44(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_119_4E70(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        short destroyMember = -1;
        fn_27_B5324(storage + 0x30, destroyMember);
        fn_119_4EE8(storage + 0x18, destroyMember);
        fn_119_4F44(storage + 0x4, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
