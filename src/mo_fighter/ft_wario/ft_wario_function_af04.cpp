#pragma force_active on
extern "C" void* fn_110_AEA4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_AF04(void* object, short deleting) {
    if (object != 0) {
        fn_110_AEA4(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
