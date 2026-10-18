#pragma force_active on
extern "C" void fn_123_3BFC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_5D3C(void* object, short deleting) {
    if (object != 0) {
        fn_123_3BFC(static_cast<unsigned char*>(object) + 0x88, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
