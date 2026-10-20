#pragma force_active on
struct S {
    int a;
    int b;
    int x : 4;
    int y : 2;
    int z : 26;
};

extern "C" int fn_74_6A80(struct S *self)
{
    return self->y;
}
