#pragma force_active on
extern "C" {
extern char lbl_27_data_36790[];
}

struct Obj {
    char *a;
    char *b;
    unsigned int c;
};

extern "C" void fn_27_1A350C(Obj *o) {
    unsigned int flag = o->c;
    flag &= 1;
    o->a = lbl_27_data_36790;
    o->b = lbl_27_data_36790 + 0x48;
    o->c = flag;
}
