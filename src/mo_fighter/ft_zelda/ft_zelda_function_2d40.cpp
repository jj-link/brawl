#pragma force_active on
extern "C" void* fn_27_BED74(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_2D40(void* object, int deleting) {
    if (object != 0) {
        fn_27_BED74(object, static_cast<short>(-1));
        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
