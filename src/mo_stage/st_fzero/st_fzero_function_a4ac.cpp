#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_61_A4AC(void* p, int flag) {
    if (p != 0 && flag > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
