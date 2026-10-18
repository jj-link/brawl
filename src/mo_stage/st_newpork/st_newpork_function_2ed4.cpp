#pragma force_active on
class grGimmick {
public:
    void stopGimmickSE(unsigned long);
};

extern "C" void fn_69_2ED4(grGimmick *self)
{
    self->stopGimmickSE(0);
}
