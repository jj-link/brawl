#pragma force_active on
extern "C" {
void fn_66_2A28(unsigned char *self, unsigned char val, int val2, float val3)
{
    *(unsigned char *)(self + 0x184) = val;
    *(int *)(self + 0x188) = val2;
    *(float *)(self + 0x18C) = val3;
}
}
