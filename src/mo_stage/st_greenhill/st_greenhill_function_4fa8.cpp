#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int c;
} S72;

extern "C" int fn_72_4FA8(S72 *p)
{
    return (int)((p->c << 4) & 0xE0000000u) >> 30;
}
