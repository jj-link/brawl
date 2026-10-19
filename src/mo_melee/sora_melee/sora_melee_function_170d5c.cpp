#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);

void* fn_27_170D5C(void* p, int flag) {
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
