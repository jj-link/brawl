#pragma force_active on
extern "C" void fn_27_689B0(void*, short);
extern "C" void fn_27_1985B4(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_118_5F5C(void* object, short deleting) {
    if (object != 0) {
        fn_27_689B0(static_cast<unsigned char*>(object) + 0x7C, -1);
        if (object != 0) {
            fn_27_1985B4(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
