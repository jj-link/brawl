#pragma force_active on
typedef unsigned int u32;

extern char lbl_27_data_35810[0x90];

struct S {
    void* vtbl;
    void* p;
    u32 flag;
};

extern "C" void fn_27_1A4858(S* s) {
    u32 f = s->flag;
    s->vtbl = lbl_27_data_35810;
    s->p = lbl_27_data_35810 + 0x48;
    s->flag = f & 1;
}
