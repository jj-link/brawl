#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_96_1609C(void* p, short size) {
    if (p != 0) {
        if (size > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
