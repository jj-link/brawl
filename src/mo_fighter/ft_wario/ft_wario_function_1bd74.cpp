#pragma force_active on
void operator delete(void*);
extern "C" void fn_110_1BDE4(void*, short);
extern "C" void* fn_110_1C0A4(void*, short);

extern "C" void* fn_110_1BD74(void* object, short deleting) {
    if (object != 0) {
        fn_110_1BDE4(static_cast<unsigned char*>(object) + 0x1978, -1);
        fn_110_1C0A4(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
