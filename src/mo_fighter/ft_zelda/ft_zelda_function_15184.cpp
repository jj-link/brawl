#pragma force_active on
extern "C" void fn_104_4FAC(void*, short);
extern "C" void* fn_104_151F4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_15184(void* object, short deleting) {
    if (object != 0) {
        fn_104_4FAC(static_cast<unsigned char*>(object) + 0x181C, -1);
        fn_104_151F4(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
