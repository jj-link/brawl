#pragma force_active on
extern "C" void* fn_105_1C04C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_1C0AC(void* object, short deleting) {
    if (object != 0) {
        fn_105_1C04C(static_cast<unsigned char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
