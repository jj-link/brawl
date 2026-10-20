#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int a : 4;
    unsigned int b : 5;
    unsigned int c : 23;
} S;

extern "C" {
int fn_78_5808(S *p)
{
    return (int)(p->b << 27) >> 28;
}
}
