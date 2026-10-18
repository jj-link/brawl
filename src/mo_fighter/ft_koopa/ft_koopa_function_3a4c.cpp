#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_102_3A4C(void* p, short flags) {
    if (p != 0 && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
