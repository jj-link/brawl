#pragma force_active on
extern "C" {
void* fn_110_4FB4(void*, short);
void __dl__FPv(void*);

void* fn_110_1BD18(void* p, short n) {
    short zero = 0;
    if (p != 0) {
        fn_110_4FB4(p, zero);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
