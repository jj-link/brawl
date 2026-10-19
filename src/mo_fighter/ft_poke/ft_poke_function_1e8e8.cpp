#pragma force_active on
extern "C" void fn_27_1A342C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_116_1E8E8(void* p, short flag) {
    if (p != 0) {
        short neg = -1;
        fn_27_1A342C(p, neg);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
