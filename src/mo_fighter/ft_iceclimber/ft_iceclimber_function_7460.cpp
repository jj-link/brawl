#pragma force_active on
extern "C" void fn_27_66114(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_105_7460(void* p, short n) {
    if (p != 0) {
        fn_27_66114(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
