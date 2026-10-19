#pragma force_active on
extern "C" void fn_27_2737A0(void*);
extern "C" void fn_27_27381C(void*);
extern "C" void update__9grGimmickFf(void*, float);
extern "C" void updateCallback__9grGimmickFUl(void*, unsigned long);

extern "C" void fn_40_33668(void* self, float deltaFrame) {
    fn_27_2737A0(self);
    fn_27_27381C(self);
    update__9grGimmickFf(self, deltaFrame);
    updateCallback__9grGimmickFUl(self, 0);
}
