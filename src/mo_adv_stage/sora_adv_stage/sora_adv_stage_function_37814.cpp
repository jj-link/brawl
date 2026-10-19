#pragma force_active on
class grGimmick;

extern "C" void __dt__9grGimmickFv(grGimmick* p, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" grGimmick* fn_40_37814(grGimmick* p, int del) {
    if (p) {
        __dt__9grGimmickFv(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
