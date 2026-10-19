#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_163C8(void*, short);
extern "C" void* fn_116_16BE4(void*, short);

extern "C" void* fn_116_16B78(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_163C8(storage + 0x43D0, -1);
        fn_116_16BE4(storage + 0x4, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
