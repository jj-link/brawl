#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_67_4AFC(void* p, int n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
