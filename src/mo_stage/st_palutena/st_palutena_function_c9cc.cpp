#pragma force_active on
struct grGimmick;

extern "C" void __dt__9grGimmickFv(grGimmick*, int);
extern "C" void __dl__FPv(void*);

extern "C" grGimmick* fn_67_C9CC(grGimmick* p, int flag)
{
    if (p != 0) {
        __dt__9grGimmickFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
