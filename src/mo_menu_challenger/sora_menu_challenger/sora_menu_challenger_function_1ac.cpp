#pragma force_active on
extern "C" {
extern void __dl__FPv(void*);
void __dt__6gfTaskFv(void*, int);

void* fn_23_1AC(void* p, int flag) {
    if (p) {
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
