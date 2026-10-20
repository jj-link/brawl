#pragma force_active on
extern "C" void* fn_100_9D4C(void*, short);
extern "C" void* fn_100_4EBC(void*, short);
extern "C" void* fn_100_4F2C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_4E44(void* object, short deleting) {
    if (object != 0) {
        int destroy = -1;
        fn_100_9D4C(static_cast<char*>(object) + 0xE0, static_cast<short>(destroy));
        fn_100_4EBC(static_cast<char*>(object) + 0x30, static_cast<short>(destroy));
        fn_100_4F2C(object, static_cast<short>(destroy));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
