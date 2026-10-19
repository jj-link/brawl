#pragma force_active on
class grGimmick {
public:
    void startGimmickSE(unsigned long);
};

extern "C" void fn_27_273AD0(grGimmick* self) {
    self->startGimmickSE(0);
    self->startGimmickSE(1);
    self->startGimmickSE(2);
}
