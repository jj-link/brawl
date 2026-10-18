#pragma force_active on
extern "C" void fn_123_BE98(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_BEF8(void* object, short deleting) {
    if (object != 0) {
        fn_123_BE98(static_cast<unsigned char*>(object) + 8, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
