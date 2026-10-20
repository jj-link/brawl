#pragma force_active on
extern "C" int fn_62_61FC(const void *p)
{
    struct S
    {
        unsigned int a;
        unsigned int b;
        unsigned int : 8;
        signed int field : 4;
    };
    const struct S *s = (const struct S *)p;
    return s->field;
}
