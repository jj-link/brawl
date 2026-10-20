#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int hi : 9;
    unsigned int f : 9;
    unsigned int lo : 14;
} S;

extern "C" void fn_48_B664(S *s, unsigned int v)
{
    s->f = v;
}
