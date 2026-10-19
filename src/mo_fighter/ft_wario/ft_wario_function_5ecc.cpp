#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_110_5ECC(void* p, short flag) {
    if (p != 0) {
        fn_27_19BFCC(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
