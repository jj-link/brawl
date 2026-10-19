#pragma force_active on
extern "C" void* fn_27_1966BC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_2C04(void* p, short flag) {
    if (p != 0) {
        fn_27_1966BC(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
