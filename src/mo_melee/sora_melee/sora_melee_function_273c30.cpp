#pragma force_active on
extern "C" void stopGimmickSE__9grGimmickFUl(void*, unsigned long);
extern "C" void startGimmickSE__9grGimmickFUl(void*, unsigned long);

extern "C" void fn_27_273C30(void* self) {
    for (unsigned int i = 0; i < 3; i++) {
        stopGimmickSE__9grGimmickFUl(self, i + 8);
    }
    for (int i = 0; i < 3; i++) {
        startGimmickSE__9grGimmickFUl(self, i + 8);
    }
}
