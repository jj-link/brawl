#pragma force_active on
typedef struct {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int mode : 2;
    unsigned int rest : 30;
} St;

#ifdef __cplusplus
extern "C" {
#endif

void fn_66_A278(St *p, unsigned int v)
{
    p->mode = v;
}

#ifdef __cplusplus
}
#endif
