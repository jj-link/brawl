#pragma force_active on
extern "C" void fn_105_10330(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_E17C(void* object, short deleting) {
    if (object != 0) {
        fn_105_10330(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
