#pragma force_active on
extern "C" {
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void* fn_18_113C(void* p, int flag);
}

void* fn_18_113C(void* p, int flag) {
    if (p) {
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
