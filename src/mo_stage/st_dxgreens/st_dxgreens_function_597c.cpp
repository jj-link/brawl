#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 12;
    unsigned int f : 6;
    unsigned int lo : 14;
} FnState;

extern "C" void fn_79_597C(FnState *s, unsigned int v)
{
    s->f = v;
}
