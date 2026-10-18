#pragma force_active on
extern "C" void fn_41_5EE64(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5E860(void* object, int flag) {
    if (object != 0) {
        fn_41_5EE64(static_cast<char*>(object) + 8, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
