#pragma force_active on
extern "C" void* fn_105_40C0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_105_4060(void* object, int deleting) {
    if (object != 0) {
        fn_105_40C0(static_cast<unsigned char*>(object) + 0xC, -1);
        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
