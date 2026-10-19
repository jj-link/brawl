#pragma force_active on
extern "C" void* fn_122_4EC0(void* object, short deleting);
extern "C" void* fn_122_5C40(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_122_4E44(void* object, short deleting) {
    if (object != 0) {
        fn_122_4EC0(static_cast<char*>(object) + 0x1A374, -1);
        if (object != 0) {
            fn_122_5C40(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
