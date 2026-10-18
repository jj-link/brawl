#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_48_35D8(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
