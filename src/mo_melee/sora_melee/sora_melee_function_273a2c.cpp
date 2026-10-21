#pragma force_active on
typedef unsigned int u32;

extern "C" void changeNodeAnim__9grGimmickFUlUl(void*, u32, u32);
extern "C" void stopGimmickSE__9grGimmickFUl(void*, u32);
extern "C" void startGimmickSE__9grGimmickFUl(void*, u32);
extern "C" void stopGimmickEffect__9grGimmickFUl(void*, u32);
extern "C" void startGimmickEffect__9grGimmickFUl(void*, u32);

extern "C" void fn_27_273A2C(void* self, u32 node, u32 anim) {
    changeNodeAnim__9grGimmickFUlUl(self, node, anim);

    for (u32 i = 0; i < 5; i++) {
        stopGimmickSE__9grGimmickFUl(self, i + 3);
    }

    for (int i = 0; i < 5; i++) {
        startGimmickSE__9grGimmickFUl(self, i + 3);
    }

    for (u32 i = 0; i < 5; i++) {
        stopGimmickEffect__9grGimmickFUl(self, i + 3);
    }

    for (int i = 0; i < 5; i++) {
        startGimmickEffect__9grGimmickFUl(self, i + 3);
    }
}
