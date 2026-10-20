#pragma force_active on
class grGimmick {
public:
    void stopGimmickEffect(unsigned long);
    void startGimmickEffect(unsigned long);
};

extern "C" void fn_27_273BC8(grGimmick* self) {
    for (unsigned long i = 0; i < 5; i++) {
        self->stopGimmickEffect(i + 3);
    }
    for (long i = 0; i < 5; i++) {
        self->startGimmickEffect(i + 3);
    }
}
