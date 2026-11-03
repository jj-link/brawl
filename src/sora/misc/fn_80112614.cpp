#pragma force_active on
extern "C" {
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}
extern void* lbl_805A0360;

extern "C" void* fn_80112614(void* p, int flag) {
    if (p) {
        lbl_805A0360 = 0;
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
