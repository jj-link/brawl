#pragma force_active on
extern "C" void fn_80099824(float *p);
extern "C" void fn_80098578(void *self, int idx)
{
    float **table = *(float ***)((char *)self + 8);
    fn_80099824(table[idx]);
}
