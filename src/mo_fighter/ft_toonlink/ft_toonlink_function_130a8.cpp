#pragma force_active on
extern "C" {
void* fn_121_1A68(void*, short);
void* fn_121_1A0C(void*, short);
}

extern "C" void* fn_121_130A8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = 0;
        fn_121_1A68(storage + 0x20, destroyMember);
        if (object) fn_121_1A0C(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
