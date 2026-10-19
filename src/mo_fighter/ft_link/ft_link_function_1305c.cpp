#pragma force_active on
extern "C" {
void fn_93_1A68(void*, short);
void fn_93_1A0C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_93_1305C(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = 0;
        fn_93_1A68(storage + 0x20, destroyMember);
        if (object) fn_93_1A0C(storage + 0x8, destroyMember);
        if (deleting > 0) __dl__FPv(object);
    }
    return object;
}
