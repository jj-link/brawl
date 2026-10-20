#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} Bits;

void fn_66_A298(unsigned char *p, unsigned int v)
{
    ((Bits *)(p + 8))->b = v;
}
}
