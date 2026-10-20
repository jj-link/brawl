#pragma force_active on
extern "C" void startGimmickSE__9grGimmickFUl(void*, unsigned long);
extern "C" void startGimmickEffect__9grGimmickFUl(void*, unsigned long);

extern "C" void fn_27_26ED70(void* self) {
    void* se = *(void**)((char*)self + 0xa8);
    if (se) {
        for (int i = 0; i < 3; i++) {
            startGimmickSE__9grGimmickFUl(self, i);
        }
    }
    void* eff = *(void**)((char*)self + 0xb0);
    if (eff) {
        for (int i = 0; i < 3; i++) {
            startGimmickEffect__9grGimmickFUl(self, i);
        }
    }
}
