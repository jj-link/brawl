#pragma force_active on
extern "C" void stopGimmickEffect__9grGimmickFUl(void*, unsigned long);
extern "C" void startGimmickEffect__9grGimmickFUl(void*, unsigned long);

extern "C" void fn_27_273C98(void* self) {
    for (unsigned i = 0; i < 3; i++) {
        stopGimmickEffect__9grGimmickFUl(self, i + 8);
    }
    for (int i = 0; i < 3; i++) {
        startGimmickEffect__9grGimmickFUl(self, i + 8);
    }
}
