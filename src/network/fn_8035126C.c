#pragma force_active on
int fn_8035126C(int *arg0)
{
    unsigned int val = (unsigned int)*arg0;
    unsigned int extracted = (val >> 11) & 3;
    unsigned int decremented = extracted - 1;
    return (int)((unsigned int)__cntlzw(decremented) >> 5);
}
