#pragma force_active on
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void fn_94_134EC(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_94_18790(void* object, short deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<char*>(object) + 0x19C9C, -1);
        fn_94_134EC(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
