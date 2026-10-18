#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_112_2248(void* p, short n) {
    if (p && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
