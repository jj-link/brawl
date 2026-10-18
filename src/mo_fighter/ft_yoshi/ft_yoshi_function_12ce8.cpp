#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_95_12CE8(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
