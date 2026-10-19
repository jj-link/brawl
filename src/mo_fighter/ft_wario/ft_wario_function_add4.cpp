#pragma force_active on
void operator delete(void*);
extern "C" void* fn_110_AD74(void*, short);
extern "C" void* fn_110_AC54(void*, short);

extern "C" void* fn_110_ADD4(void* object, short deleting) {
    if (object != 0) {
        fn_110_AD74(static_cast<unsigned char*>(object) + 0x60, -1);
        fn_110_AC54(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
