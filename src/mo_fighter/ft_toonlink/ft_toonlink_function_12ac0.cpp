#pragma force_active on
extern "C" {
void __dl__FPv(void* p);

void* fn_121_12AC0(void* p, short size) {
    if (p != 0 && size > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
