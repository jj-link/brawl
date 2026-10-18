#pragma force_active on
extern "C" void __dl__FPv(void* p);

extern "C" {
void* fn_104_246CC(void* p, short n) {
    if (p != 0) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
