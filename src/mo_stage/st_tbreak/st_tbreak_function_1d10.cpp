#pragma force_active on
class grGimmick {
public:
    void startGimmickSE(unsigned long);
};

extern "C" void fn_89_1D10(grGimmick *self)
{
    self->startGimmickSE(0);
}
