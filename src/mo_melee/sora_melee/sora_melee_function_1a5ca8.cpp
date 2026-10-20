#pragma force_active on
extern "C" {
extern char lbl_27_data_346E8[];

struct fn_27_1A5CA8_Obj {
    void *vtbl;
    void *ptr;
    unsigned int flag;
};

void fn_27_1A5CA8(fn_27_1A5CA8_Obj *p)
{
    p->vtbl = lbl_27_data_346E8;
    p->ptr = lbl_27_data_346E8 + 0x48;
    p->flag = p->flag & 1;
}
}
