#pragma force_active on
typedef unsigned char u8;

struct Obj {
    u8 flag : 1;
    u8 rest : 7;
    int val;
    u8 pad[0x10];
    void *vt;
};

extern "C" {
extern u8 lbl_27_data_B310[0xC];

void fn_27_C9960(Obj *p)
{
    p->flag = 0;
    p->vt = lbl_27_data_B310;
    p->val = 0;
}
}
