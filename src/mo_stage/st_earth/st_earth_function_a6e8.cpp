#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 4;
    unsigned int f : 4;
    unsigned int lo : 24;
} S;

extern "C" void fn_66_A6E8(S *s, unsigned int v)
{
    s->f = v;
}
