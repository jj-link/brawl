#pragma force_active on
extern "C" void* fn_27_5CC1C(void*, short);
extern "C" void* fn_27_D3080(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_151E0(void* object, short deleting) {
    if (object != 0) {
        fn_27_5CC1C(static_cast<unsigned char*>(object) + 0xAC, -1);
        if (object != 0) {
            fn_27_D3080(object, -1);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
