#pragma force_active on
extern "C" void* fn_104_17EF8(void*, short);
extern "C" void* fn_104_186B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_1864C(void* object, short deleting) {
    if (object != 0) {
        fn_104_17EF8(static_cast<unsigned char*>(object) + 0x6F68, -1);
        fn_104_186B8(static_cast<unsigned char*>(object) + 0x4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
