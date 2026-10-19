#pragma force_active on
extern "C" {
void fn_49_1414(void*, int);
void __dl__FPv(void*);

void* fn_49_BA84(void* p, int flag) {
    if (p) {
        fn_49_1414(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
