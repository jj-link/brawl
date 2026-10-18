#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_107_12870(void* a, short b) {
    if (a && b > 0)
        __dl__FPv(a);
    return a;
}
}
