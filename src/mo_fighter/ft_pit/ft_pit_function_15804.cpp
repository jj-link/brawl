#pragma force_active on
extern "C" {
void* fn_27_1A301C(void*, short);
void __dl__FPv(void*);

void* fn_112_15804(void* p, short flag) {
    if (p != 0) {
        fn_27_1A301C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
