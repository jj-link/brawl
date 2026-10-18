#pragma force_active on
extern "C" void fn_124_9D58(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_9DB8(void* object, int flag) {
    if (object != 0) {
        fn_124_9D58(static_cast<char*>(object) + 4, static_cast<short>(-1));
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
