#pragma force_active on
extern "C" {
typedef struct {
    unsigned int a : 8;
    unsigned int b : 8;
    unsigned int c : 16;
} F;

void fn_27_CE048(F *p, unsigned int v)
{
    p[2].b = v;
}
}
