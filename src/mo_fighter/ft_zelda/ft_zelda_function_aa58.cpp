#pragma force_active on
typedef struct {
    unsigned char pad[0x14];
    float *values;
} FtZeldaWork;

extern "C" void fn_104_AA58(FtZeldaWork *self, unsigned int index, float value)
{
    self->values[index] = self->values[index] - value;
}
