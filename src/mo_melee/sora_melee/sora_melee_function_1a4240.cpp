#pragma force_active on
extern "C" char lbl_27_data_35DE0[];

struct fn_27_S {
    void *vtbl;
    void *vtbl2;
    unsigned int flag;
};

extern "C" void fn_27_1A4240(fn_27_S *p)
{
    unsigned int f = p->flag;
    char *base = lbl_27_data_35DE0;
    p->vtbl = base;
    p->vtbl2 = base + 0x48;
    p->flag = f & 1;
}
