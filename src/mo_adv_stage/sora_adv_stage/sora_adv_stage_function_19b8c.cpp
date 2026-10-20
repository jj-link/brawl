#pragma force_active on
extern "C" void __dt__9grGimmickFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_40_19B8C(void* p, int flag) {
    if (p) {
        __dt__9grGimmickFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
