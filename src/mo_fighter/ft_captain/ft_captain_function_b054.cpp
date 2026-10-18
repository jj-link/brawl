#pragma force_active on
extern "C" void fn_100_AFF4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_B054(void* object, int flag) {
    if (object) {
        fn_100_AFF4(static_cast<char*>(object) + 8, -1);
        if (static_cast<short>(flag) > 0)
            __dl__FPv(object);
    }
    return object;
}
