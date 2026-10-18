#pragma force_active on
typedef unsigned short u16;
typedef short s16;

extern "C" {
extern char lbl_27_data_21030[];
}

struct Fn27Obj {
    void* vtbl;
    s16 a;
    s16 b;
    s16 c;
};

extern "C" void fn_27_D5038(Fn27Obj* p, s16 x) {
    p->a = -1;
    p->vtbl = lbl_27_data_21030;
    p->b = x;
    p->c = -1;
}
