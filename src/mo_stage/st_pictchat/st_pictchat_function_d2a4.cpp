#pragma force_active on
class grGimmickLadder;

extern "C" {
void __dt__15grGimmickLadderFv(grGimmickLadder* self, int flag);
void __dl__FPv(void* p);

grGimmickLadder* fn_73_D2A4(grGimmickLadder* self, int flag) {
    if (self) {
        __dt__15grGimmickLadderFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
