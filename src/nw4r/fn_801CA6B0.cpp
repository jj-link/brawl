#pragma force_active on
extern "C" {

void __dl__FPv(void*);
void fn_801CA880(void*, int);

void* fn_801CA6B0(void* p, int n) {
    if (p) {
        fn_801CA880(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

}
