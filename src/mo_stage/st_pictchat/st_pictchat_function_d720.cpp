#pragma force_active on
extern "C" {
void __dt__15grGimmickSpringFv(void* this_, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_73_D720(void* p, int flag) {
    if (p) {
        __dt__15grGimmickSpringFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
