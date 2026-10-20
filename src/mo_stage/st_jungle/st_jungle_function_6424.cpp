#pragma force_active on
typedef struct { unsigned int a:2; unsigned int b:2; unsigned int c:28; } F;

extern "C" void fn_51_6424(unsigned char *p, unsigned int v)
{
    F *f = (F *)(p + 8);
    f->b = v;
}
