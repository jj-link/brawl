#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_189E8(void*, short);
extern "C" void* fn_116_5570(void*, short);
extern "C" void* fn_116_55E0(void*, short);

extern "C" void* fn_116_16D1C(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_189E8(storage + 0xE0, -1);
        fn_116_5570(storage + 0x30, -1);
        fn_116_55E0(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
