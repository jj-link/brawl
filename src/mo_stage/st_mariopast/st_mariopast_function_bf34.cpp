#pragma force_active on
typedef struct {
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
} S;

extern "C" void fn_48_BF34(S *obj, unsigned int val)
{
    unsigned int i = 0;
    ((S *)((unsigned int *)obj + 2))->b = val;
}
