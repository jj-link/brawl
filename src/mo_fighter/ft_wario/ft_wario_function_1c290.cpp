#pragma force_active on
extern "C" void* fn_110_1C308(void* p, short n);
extern "C" void* fn_110_1C348(void* object, short deleting);
extern "C" void* fn_110_1C3A8(void* object, short deleting);
void operator delete(void*);

extern "C" void* fn_110_1C290(void* object, short deleting) {
    if (object != 0) {
        fn_110_1C308(static_cast<unsigned char*>(object) + 0xB0, -1);
        fn_110_1C348(static_cast<unsigned char*>(object) + 0x30, -1);
        fn_110_1C3A8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
