#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_104_2476C(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
