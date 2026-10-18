#pragma force_active on
extern "C" {
extern char lbl_121_data_3DAC[];

void fn_121_1AC4(void *self, char val)
{
    *(void **)self = lbl_121_data_3DAC;
    ((char *)self)[4] = val;
}
}
