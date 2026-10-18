#pragma force_active on
typedef struct {
    int a;
    float x;
    float y;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned char e;
} FnStruct;

extern "C" void fn_95_11ABC(FnStruct *s, int a, float x, float y, unsigned char b, unsigned char c, unsigned char d, unsigned char e)
{
    s->a = a;
    s->x = x;
    s->y = y;
    s->b = b;
    s->c = c;
    s->d = d;
    s->e = e;
}
