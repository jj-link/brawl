#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} St;

void fn_61_A7B8(St *p, unsigned int v)
{
    p->b = v;
}
}
