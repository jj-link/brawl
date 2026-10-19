#pragma force_active on
class grGimmick {
public:
    void startGimmickEffect(unsigned long);
};

extern "C" void fn_27_273B18(grGimmick* self) {
    self->startGimmickEffect(0);
    self->startGimmickEffect(1);
    self->startGimmickEffect(2);
}
