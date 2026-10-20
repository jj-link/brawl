#pragma force_active on
extern "C" void fn_27_20BEF8(char *self, float a, float b, float c);

extern "C" void fn_27_20BE48(char *self, float x)
{
    float a = *(float *)(self + 0x5c);
    float b = *(float *)(self + 0x80);
    float c = *(float *)(self + 0x88);
    fn_27_20BEF8(self, x - a, b, c);
}
