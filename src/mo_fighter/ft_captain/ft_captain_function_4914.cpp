#pragma force_active on
extern "C" void fn_100_4974(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_100_4914(void* object, int flag) {
    if (object != 0) {
        fn_100_4974(static_cast<char*>(object) + 8, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
