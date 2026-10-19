#include <types.h>
#include <gr/gr_gimmick.h>
#pragma force_active on

extern "C" void fn_27_26A954(grGimmick*);
extern "C" void updataGimmickEffect__9grGimmickFf(grGimmick*, float);

extern "C" void fixedPosition__9grGimmickFf(grGimmick* self, float value) {
    fn_27_26A954(self);
    updataGimmickEffect__9grGimmickFf(self, value);
}
