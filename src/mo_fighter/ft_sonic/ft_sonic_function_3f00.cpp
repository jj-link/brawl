#pragma force_active on
extern "C" void fn_123_3F60(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_3F00(void* object, short deleting) {
    if (object != 0) {
        fn_123_3F60(static_cast<unsigned char*>(object) + 0xC, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
