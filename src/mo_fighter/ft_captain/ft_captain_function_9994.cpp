#pragma force_active on
struct CaptainFalconData
{
    int field0;
    int field4;
    int field8;
    int *fieldC;
};

extern "C" void fn_100_9994(CaptainFalconData *self, int divisor, int index)
{
    if (divisor != 0)
        self->fieldC[index] /= divisor;
}
