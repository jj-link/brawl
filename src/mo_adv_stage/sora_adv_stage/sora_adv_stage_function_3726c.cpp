#pragma force_active on
struct grGimmick;

extern "C" void __dt__9grGimmickFv(grGimmick*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_40_3726C(grGimmick* p, int flag) {
    if (p) {
        __dt__9grGimmickFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
