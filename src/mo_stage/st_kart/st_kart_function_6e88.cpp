#pragma force_active on
typedef struct S {
    int pad[2];
    unsigned int a : 4;
    int b : 2;
    unsigned int c : 26;
} S;

extern "C" int fn_49_6E88(S *s)
{
    return s->b;
}
