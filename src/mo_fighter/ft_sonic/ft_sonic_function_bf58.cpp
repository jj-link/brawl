#pragma force_active on
extern "C" void fn_123_BEF8(void*, short);
extern "C" void fn_123_BDC0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_BF58(void* object, short deleting) {
    if (object != 0) {
        fn_123_BEF8(static_cast<unsigned char*>(object) + 0x17C, -1);
        if (object != 0) {
            fn_123_BDC0(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
