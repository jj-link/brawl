#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_348D8[];

struct Foo {
    void* vt0;
    void* vt1;
    u32 flag;
};

void fn_27_1A5AA0(Foo* p) {
    u32 f = p->flag;
    p->vt0 = lbl_27_data_348D8;
    p->vt1 = lbl_27_data_348D8 + 0x48;
    p->flag = f & 1;
}
}
