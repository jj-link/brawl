#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_27_2904BC(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
