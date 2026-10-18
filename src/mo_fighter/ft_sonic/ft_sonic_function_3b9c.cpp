#pragma force_active on
extern "C" void fn_123_3BFC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_3B9C(void* object, short deleting) {
    if (object != 0) {
        fn_123_3BFC(static_cast<unsigned char*>(object) + 0x38, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
