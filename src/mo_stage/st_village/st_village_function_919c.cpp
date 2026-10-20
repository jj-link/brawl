#pragma force_active on
typedef struct {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 26;
} Field;

extern "C" void fn_70_919C(unsigned char *p, unsigned int x)
{
    Field *f = (Field *)(p + 8);
    f->b = x;
}
