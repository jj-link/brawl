#pragma force_active on
typedef struct Obj {
    unsigned char pad0[0x60];
    float a;
    unsigned char pad1[0x20];
    float b;
    unsigned char pad2[0x4];
    float c;
} Obj;

extern "C" void fn_27_20BEF8(Obj *p, float f1, float f2, float f3);

extern "C" void fn_27_20BE5C(Obj *p, float f1)
{
    fn_27_20BEF8(p, f1 - p->a, p->b, p->c);
}
