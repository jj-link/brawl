#pragma force_active on
extern "C" void fn_79_5A30(void *p, unsigned int v)
{
    struct S {
        int a;
        int b;
        unsigned int f : 2;
        unsigned int g : 30;
    };
    ((S *)p)->f = v;
}
