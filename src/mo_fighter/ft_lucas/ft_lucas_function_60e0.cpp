#pragma force_active on
extern "C" void* fn_114_5D0C(void* object, short deleting);
extern "C" void* fn_114_6150(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_60E0(void* object, int deleting) {
    if (object != 0) {
        fn_114_5D0C(static_cast<char*>(object) + 0x16D40, -1);
        fn_114_6150(static_cast<char*>(object) + 4, -1);

        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
