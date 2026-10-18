#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_121_5F68(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
