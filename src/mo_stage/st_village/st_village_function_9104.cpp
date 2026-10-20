#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int :4;
    unsigned int f:2;
    unsigned int :26;
} S;

extern "C" {
void fn_70_9104(S *s, unsigned int v)
{
    s->f = v;
}
}
