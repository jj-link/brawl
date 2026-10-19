#pragma force_active on
extern "C" void* fn_96_2F0F8(void*, short);
extern "C" void* fn_96_2F214(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_2F088(void* object, short deleting) {
    if (object != 0) {
        fn_96_2F0F8(static_cast<unsigned char*>(object) + 0x1560, -1);
        fn_96_2F214(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
