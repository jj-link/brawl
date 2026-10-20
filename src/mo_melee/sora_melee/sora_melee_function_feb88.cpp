#pragma force_active on
struct fn_27_Obj {
    unsigned int pad[2];
    unsigned int flag : 2;
    unsigned int rest : 30;
};

extern "C" void fn_27_FEB88(fn_27_Obj *p, unsigned int v) {
    p->flag = v;
}
