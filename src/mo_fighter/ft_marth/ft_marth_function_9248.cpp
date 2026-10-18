#pragma force_active on
typedef signed short s16;

extern "C" void fn_106_91E8(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_9248(void* object, s16 flag) {
    if (object != 0) {
        fn_106_91E8(static_cast<char*>(object) + 8, -1);
        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
