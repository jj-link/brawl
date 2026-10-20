#pragma force_active on
typedef struct SomeObj
{
    unsigned int w0;
    unsigned int w1;
    struct
    {
        unsigned int a : 8;
        unsigned int b : 4;
        unsigned int c : 12;
    } f;
} SomeObj;

extern "C" {
void fn_52_76D0(SomeObj *p, unsigned int v)
{
    p->f.b = v;
}
}
