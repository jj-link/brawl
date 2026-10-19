#pragma force_active on
extern "C" {
void* fn_27_14B698(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_120_59DC(void* p, short flag) {
    if (p != 0) {
        fn_27_14B698(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
