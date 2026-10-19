#pragma force_active on
class grGimmickLadder {
public:
    ~grGimmickLadder();
};

extern "C" void __dt__15grGimmickLadderFv(grGimmickLadder* p, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" grGimmickLadder* fn_51_156F4(grGimmickLadder* p, int flag) {
    if (p) {
        __dt__15grGimmickLadderFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
