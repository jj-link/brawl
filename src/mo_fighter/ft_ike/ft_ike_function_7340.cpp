#pragma force_active on
struct S {
    void* a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
};

extern "C" {
extern char lbl_119_data_1804[];

void fn_119_7340(S* s, int e, int f, int g)
{
    s->a = &lbl_119_data_1804;
    s->e = e;
    s->f = f;
    s->g = g;
}
}
