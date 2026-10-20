#pragma force_active on
typedef struct Foo {
    int a;
    int b;
    unsigned int c;
} Foo;

extern "C" int fn_27_C44A0(Foo* p)
{
    return ((int)((p->c << 6) & 0xFE000000)) >> 26;
}
