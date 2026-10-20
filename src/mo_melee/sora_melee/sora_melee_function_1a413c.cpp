#pragma force_active on
extern "C" {
extern char lbl_27_data_35ED8[];

struct Obj {
    void *a;
    void *b;
    unsigned int c;
};

void fn_27_1A413C(Obj *p) {
    p->a = lbl_27_data_35ED8;
    p->b = lbl_27_data_35ED8 + 0x48;
    p->c = p->c & 1;
}
}
