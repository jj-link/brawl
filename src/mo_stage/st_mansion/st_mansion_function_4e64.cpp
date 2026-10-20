#pragma force_active on
typedef struct Obj {
    unsigned char pad[8];
    unsigned int hi : 2;
    unsigned int rest : 30;
} Obj;

#ifdef __cplusplus
extern "C" {
#endif

void fn_47_4E64(Obj *p, unsigned int v)
{
    p->hi = v;
}

#ifdef __cplusplus
}
#endif
