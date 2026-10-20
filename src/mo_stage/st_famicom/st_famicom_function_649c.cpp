#pragma force_active on
typedef struct {
    int a;
    int b;
    unsigned int f : 2;
    unsigned int rest : 30;
} S;

#ifdef __cplusplus
extern "C" {
#endif
void fn_68_649C(S *p, unsigned int v)
{
    p->f = v;
}
#ifdef __cplusplus
}
#endif
