#pragma force_active on
extern "C" void* fn_27_19816C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_123_2DB8(void* p, short flag) {
    if (p) {
        fn_27_19816C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
