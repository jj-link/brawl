#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int pre : 3;
    unsigned int field : 3;
    unsigned int post : 26;
} S;

void fn_51_D8B0(S *s, unsigned int v)
{
    s->field = v;
}
}
