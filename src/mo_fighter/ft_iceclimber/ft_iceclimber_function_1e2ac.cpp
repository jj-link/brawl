#pragma force_active on
extern "C" void* fn_105_1E31C(void*, short);
extern "C" void* fn_105_1E438(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_1E2AC(void* object, short deleting) {
    if (object != 0) {
        fn_105_1E31C(static_cast<unsigned char*>(object) + 0x19E4, -1);
        fn_105_1E438(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
