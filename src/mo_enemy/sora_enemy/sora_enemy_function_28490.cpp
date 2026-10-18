#pragma force_active on
typedef unsigned char u8;

struct Fn41Obj {
    void *a;
    u8 flag;
    void *b;
    void *c;
};

extern "C" void fn_41_28490(Fn41Obj *obj, void *p4, void *p5, void *p6) {
    obj->a = p4;
    obj->flag = 0;
    obj->b = p5;
    obj->c = p6;
}
