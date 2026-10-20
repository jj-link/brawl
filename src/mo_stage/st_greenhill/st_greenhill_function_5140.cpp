#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int top : 4;
    unsigned int f : 2;
    unsigned int rest : 26;
} FlagsHolder;

extern "C" {
void fn_72_5140(FlagsHolder *p, unsigned int v)
{
    p->f = v;
}
}
