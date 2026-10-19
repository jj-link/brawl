#pragma force_active on
extern "C" void fn_41_5EE64(void*, short);
extern "C" void fn_41_5EBB4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5EC20(void* object, int flag) {
    if (object != 0) {
        fn_41_5EE64(static_cast<char*>(object) + 0x1B8, -1);
        fn_41_5EBB4(static_cast<char*>(object) + 4, -1);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
