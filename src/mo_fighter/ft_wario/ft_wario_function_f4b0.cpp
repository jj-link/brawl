#pragma force_active on
void operator delete(void*);
extern "C" void fn_110_F520(void*, short);
extern "C" void fn_110_F7E0(void*, short);

extern "C" void* fn_110_F4B0(void* object, short deleting) {
    if (object != 0) {
        fn_110_F520(static_cast<unsigned char*>(object) + 0x2300, -1);
        fn_110_F7E0(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
