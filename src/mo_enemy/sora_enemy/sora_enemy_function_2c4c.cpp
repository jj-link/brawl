#pragma force_active on
extern "C" void fn_27_C87A8(void*, short);
extern "C" void* fn_41_2BEC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2C4C(void* p, short flags) {
    if (p != 0) {
        fn_27_C87A8((char*)p + 0x10, -1);
        fn_41_2BEC(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
