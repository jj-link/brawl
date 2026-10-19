#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_13210(void*, short);
extern "C" void* fn_110_130F0(void*, short);

extern "C" void* fn_110_13270(void* object, short deleting) {
    if (object != 0) {
        fn_110_13210(static_cast<unsigned char*>(object) + 0x44, -1);
        fn_110_130F0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
