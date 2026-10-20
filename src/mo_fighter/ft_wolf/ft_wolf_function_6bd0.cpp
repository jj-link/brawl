#pragma force_active on
extern "C" void* fn_27_1A1E70(void*, short);
extern "C" void fn_125_6C48(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_6BD0(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A1E70(static_cast<char*>(object) + 0x190, -1);
        if (object != 0) {
            fn_125_6C48(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
