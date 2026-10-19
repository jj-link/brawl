#pragma force_active on
extern "C" void* fn_116_45E8(void*, short);
extern "C" void* fn_116_4D28(void*, short);

extern "C" void* fn_116_457C(void* object, short deleting) {
    if (object != 0) {
        fn_116_45E8(static_cast<unsigned char*>(object) + 0x18FC, -1);
        fn_116_4D28(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
