#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_95_41DC(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
