#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_94_1D868(void* p, short n) {
    if (p != 0) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
