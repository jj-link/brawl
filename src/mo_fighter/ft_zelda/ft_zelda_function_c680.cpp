#pragma force_active on
extern "C" void* fn_104_C620(void* object, short deleting);
extern "C" void* fn_104_C4E8(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_C680(void* object, short deleting) {
    if (object != 0) {
        fn_104_C620(static_cast<char*>(object) + 0xEC, -1);
        if (object != 0) {
            fn_104_C4E8(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
