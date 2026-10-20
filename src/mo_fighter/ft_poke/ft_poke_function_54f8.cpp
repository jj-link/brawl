#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_ACC4(void*, short);
extern "C" void* fn_116_5570(void*, short);
extern "C" void* fn_116_55E0(void*, short);

extern "C" void* fn_116_54F8(void* object, short deleting) {
    if (object != 0) {
        fn_116_ACC4(static_cast<unsigned char*>(object) + 0xE0, -1);
        fn_116_5570(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_116_55E0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
