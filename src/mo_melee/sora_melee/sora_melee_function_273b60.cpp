#pragma force_active on
class grGimmick {
public:
    void startGimmickSE(unsigned long);
    void stopGimmickSE(unsigned long);
};

extern "C" void fn_27_273B60(grGimmick* self) {
    unsigned long i;
    for (i = 0; i < 5; i++) {
        self->stopGimmickSE(i + 3);
    }
    int j;
    for (j = 0; j < 5; j++) {
        self->startGimmickSE(j + 3);
    }
}
