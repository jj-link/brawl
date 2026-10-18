#pragma force_active on
typedef struct {
    int a;
    int b;
    int c;
} St;

extern "C" {
int fn_63_9D4C(St *s)
{
    int x = s->c;
    x = (x << 4) & 0xF8000000;
    return x >> 28;
}
}
