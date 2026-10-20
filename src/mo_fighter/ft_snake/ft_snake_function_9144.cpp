#pragma force_active on
extern "C" void fn_27_1A1E70(void* object, short deleting);
extern "C" void fn_122_91BC(void* object, short deleting);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_122_9144(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x4B8, -1);
        if (object != 0) {
            fn_122_91BC(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
