#pragma force_active on
extern "C" void* fn_120_B460(void*, short);
extern "C" void* fn_120_B330(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_B4C0(void* object, short deleting) {
    if (object != 0) {
        fn_120_B460(static_cast<char*>(object) + 0x94, -1);
        if (object != 0) {
            fn_120_B330(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
