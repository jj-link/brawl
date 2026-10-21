#pragma force_active on
typedef signed short s16;
typedef signed int s32;

extern "C" {
extern char lbl_804878B4[];

struct Fn802D7F20Obj {
    void *ptr;
    s16 a;
    s16 b;
    s32 c;
};

void fn_802D7F20(Fn802D7F20Obj *p, s32 arg1) {
    p->b = 1;
    p->ptr = &lbl_804878B4;
    p->c = arg1;
}
}
