#pragma force_active on
extern "C" {
void* fn_27_D3B50(void*, short);
void __dl__FPv(void*);

void* fn_122_38A0(void* p, short flag) {
    if (p != 0) {
        fn_27_D3B50(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
