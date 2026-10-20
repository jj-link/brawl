#pragma force_active on
extern "C" {
typedef struct {
    int a;
    int b;
    unsigned int c;
} S72;

int fn_72_53F8(S72 *p)
{
    unsigned int x = p->c;
    int r = (int)(((x << 8) | (x >> 24)) & 0xF8000000u);
    return r >> 28;
}
}
