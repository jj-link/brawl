#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_163C8(void*, short);
extern "C" void* fn_116_16B0C(void*, short);

extern "C" void* fn_116_16AA0(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_163C8(storage + 0x7100, -1);
        fn_116_16B0C(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
