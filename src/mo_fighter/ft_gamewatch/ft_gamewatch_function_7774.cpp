#pragma force_active on
extern "C" void fn_27_19BFCC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_7774(void* p, short flags) {
    if (p != 0) {
        fn_27_19BFCC(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
