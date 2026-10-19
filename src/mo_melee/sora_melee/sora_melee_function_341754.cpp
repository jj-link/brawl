#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_27_341754(void* p, int flag) {
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
