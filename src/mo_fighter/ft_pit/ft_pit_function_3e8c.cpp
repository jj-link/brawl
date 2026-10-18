#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_112_3E8C(void* p, short flags) {
    if (p != 0) {
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
