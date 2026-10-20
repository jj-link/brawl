#pragma force_active on
extern "C" void* fn_27_1A1B88(void* member, short deleteFlag);
extern "C" void* fn_102_4EF0(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_4E78(void* object, int deleting) {
    if (object != 0) {
        fn_27_1A1B88(static_cast<unsigned char*>(object) + 0x88, -1);
        if (object != 0) {
            fn_102_4EF0(object, 0);
        }
        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
