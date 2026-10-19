#pragma force_active on
extern "C" {
void* fn_110_2024(void*, short);
void* fn_110_1FC8(void*, short);
}

extern "C" void* fn_110_1C3A8(void* object, short deleting) {
    if (object) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        int destroyMember = 0;
        fn_110_2024(storage + 0x20, destroyMember);
        if (object) fn_110_1FC8(storage + 0x8, destroyMember);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
