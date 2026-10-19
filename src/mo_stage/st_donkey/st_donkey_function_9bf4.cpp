#pragma force_active on
class grGimmickLadder {
public:
    ~grGimmickLadder();
};

extern "C" void __dt__15grGimmickLadderFv(grGimmickLadder* self, int flag);

extern "C" {
grGimmickLadder* fn_50_9BF4(grGimmickLadder* self, int del) {
    if (self) {
        __dt__15grGimmickLadderFv(self, 0);
        if (del > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
