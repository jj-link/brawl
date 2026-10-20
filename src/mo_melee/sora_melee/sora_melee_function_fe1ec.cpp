#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    short c;
    short d;
} fn_27_FE1EC_S;

extern "C" {
void fn_27_FE1EC(fn_27_FE1EC_S* dst, unsigned int* src, unsigned int val, short* src2, short val2)
{
    src = (unsigned int*)*src;
    short c = *src2;
    dst->a = (unsigned int)src;
    dst->b = val;
    dst->c = c;
    dst->d = val2;
}
}
