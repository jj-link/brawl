#pragma force_active on
extern "C" {
void* fn_116_163C8(void*, short);
void* fn_116_169C0(void*, short);
}

extern "C" void* fn_116_16950(void* object, short deleting) {
    if (object != 0) {
        fn_116_163C8(static_cast<unsigned char*>(object) + 0xB4C8, static_cast<short>(-1));
        fn_116_169C0(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
