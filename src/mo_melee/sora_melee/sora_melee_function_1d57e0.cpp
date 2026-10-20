#pragma force_active on
typedef struct {
    int a;
    int b;
    int c;
} Vec3Zero;

extern "C" {
void fn_27_1D57E0(Vec3Zero *p)
{
    p->a = 0;
    p->b = 0;
    p->c = 0;
}
}
