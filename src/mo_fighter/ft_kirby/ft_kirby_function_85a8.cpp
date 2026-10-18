#pragma force_active on
extern "C" void fn_96_817C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_85A8(void* object, int deleting) {
    if (object != 0) {
        fn_96_817C(static_cast<unsigned char*>(object) + 4, -1);
        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
