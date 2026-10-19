#pragma force_active on
extern "C" void* fn_114_5D0C(void* object, short deleting);
extern "C" void* fn_114_6680(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_114_6614(void* object, short deleting) {
    if (object != 0) {
        fn_114_5D0C(static_cast<char*>(object) + 0x1C20, -1);
        fn_114_6680(static_cast<char*>(object) + 4, -1);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
