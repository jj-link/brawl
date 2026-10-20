#pragma force_active on
extern "C" void* fn_125_D240(void* object, short deleting);
extern "C" void fn_125_D108(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_D2A0(void* object, short deleting) {
    if (object != 0) {
        fn_125_D240(static_cast<char*>(object) + 0x17C, -1);
        if (object != 0) {
            fn_125_D108(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
