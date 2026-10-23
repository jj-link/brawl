#pragma force_active on
typedef int s32;

struct Obj {
    s32 state;
    char pad[0x7D8 - 4];
    void *list;
};

extern void fn_8038862C(void **);
extern void *fn_803889C0(void *);
extern s32 fn_8038CCCC(struct Obj *);
extern s32 fn_8038D150(struct Obj *);

s32 fn_8038D2E8(struct Obj *arg0) {
    void *sp8;
    void *node;

    node = arg0->list;
    if (node != 0) {
        sp8 = node;
        while (sp8 != 0) {
            node = fn_803889C0(sp8);
            fn_8038862C(&sp8);
            sp8 = node;
        }
        arg0->list = 0;
    }

    switch (arg0->state) {
    case 2:
    case 3:
        return fn_8038CCCC(arg0);
    case 0:
        return fn_8038D150(arg0);
    default:
        return 0;
    }
}
