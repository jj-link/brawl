#pragma force_active on
extern "C" void* fn_104_17EF8(void*, short);
extern "C" void* fn_104_187FC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_18790(void* object, short deleting) {
    if (object != 0) {
        fn_104_17EF8(static_cast<unsigned char*>(object) + 0x1BE0, -1);
        fn_104_187FC(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
