#pragma force_active on
extern "C" void fn_27_1A2524(void*, short);
extern "C" void* fn_122_4394(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_9AD8(void* object, int deleting) {
    if (object != 0) {
        fn_27_1A2524(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_122_4394(object, 0);
        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
