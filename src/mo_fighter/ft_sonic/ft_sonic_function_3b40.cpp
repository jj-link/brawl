#pragma force_active on
extern "C" void* fn_27_5C674(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_3B40(void* p, short flag) {
    if (p != 0) {
        fn_27_5C674(p, static_cast<short>(-1));
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
