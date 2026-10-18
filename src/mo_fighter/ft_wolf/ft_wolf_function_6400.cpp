#pragma force_active on
extern "C" void fn_125_3B44(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_6400(void* object, int deleting) {
    if (object != 0) {
        fn_125_3B44(static_cast<unsigned char*>(object) + 0x1C0, -1);
        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
