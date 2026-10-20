#pragma force_active on
typedef struct {
    int a;
    int b;
    int c;
} LocalTriple;

extern "C" void* fn_27_7BE50(void)
{
    LocalTriple t;
    t.a = -1;
    t.b = -1;
    t.c = 0;
    return &t;
}
