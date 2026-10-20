#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;

struct fn_27_2ADF94_obj {
    u8 flag : 1;
    u8 rest : 7;
    u8 pad[7];
    s8 field8;
    s8 field9;
};

extern "C" void fn_27_2ADF94(fn_27_2ADF94_obj *p) {
    p->flag = 0;
    p->field8 = -1;
    p->field9 = -1;
}
