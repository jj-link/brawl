#pragma force_active on
extern "C" {
void fn_92_1B7C(void*, short);
void __dl__FPv(void*);

void* fn_92_1CF4(void* p, short flag) {
    if (p) {
        fn_92_1B7C(p, 0);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
}
