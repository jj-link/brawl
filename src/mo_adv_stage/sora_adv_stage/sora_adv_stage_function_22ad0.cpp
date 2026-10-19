#pragma force_active on
class grGimmick;

extern "C" void __dt__9grGimmickFv(grGimmick* p, int flag);

extern "C" grGimmick* fn_40_22AD0(grGimmick* p, int del) {
    if (p) {
        __dt__9grGimmickFv(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}
