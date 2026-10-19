#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);
extern "C" void fn_27_264DDC(void* self);

extern "C" void fn_40_1CCE0(void* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (*((unsigned char*)self + 0x170)) {
        *((unsigned char*)self + 0x170) = 0;
        fn_27_264DDC(self);
    }
}
