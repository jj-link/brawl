#pragma force_active on
extern "C" void fn_27_64D9C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_112_6B88(void* p, int flag) {
    if (p != 0) {
        fn_27_64D9C(p, -1);
        if (static_cast<short>(flag) > 0)
            __dl__FPv(p);
    }
    return p;
}
