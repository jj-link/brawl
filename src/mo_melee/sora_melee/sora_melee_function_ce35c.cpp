#pragma force_active on
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    struct {
        unsigned int a : 5;
        unsigned int rest : 27;
    } unk8;
} FnObj;

extern "C" {
void fn_27_CE35C(FnObj *p, unsigned int v)
{
    p->unk8.a = v;
}
}
