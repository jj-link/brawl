#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_66_8FEC(void* p, int flags) {
    if (p != 0 && flags > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
