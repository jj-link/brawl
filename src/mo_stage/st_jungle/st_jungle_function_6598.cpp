#pragma force_active on
extern "C" {
typedef struct {
    unsigned int pad[2];
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
} Fields;

void fn_51_6598(Fields *p, unsigned int v)
{
    p->b = v;
}
}
