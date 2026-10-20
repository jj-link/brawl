#pragma force_active on
typedef struct Foo {
    int a;
    int b;
    signed int pad : 6;
    signed int f : 3;
    signed int rest : 23;
} Foo;

extern "C" int fn_27_198504(Foo *p)
{
    return p->f;
}
