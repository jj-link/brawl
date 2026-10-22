#pragma force_active on
extern void fn_80335638(int, const char *, ...);
extern void fn_80336F14(int, int);
extern void fn_80338938(int, int);
extern void fn_80341220(int, int);
extern char lbl_8048A384[];
extern char lbl_8048A398[];

struct Obj {
    char pad[0x24];
    int unk24;
    char pad2[0x9c - 0x28];
    int unk9c;
};

extern struct Obj *lbl_805A0F88;

int fn_8033AEEC(int arg0) {
    int r31;
    int r30;
    struct Obj *obj;

    if (arg0 == 0) {
        return 0;
    }
    fn_80335638(2, lbl_8048A384, arg0);
    switch (arg0) {
    case 1:
        r30 = 9;
        r31 = -1;
        break;
    case 2:
        r30 = 9;
        r31 = -2;
        break;
    case 3:
        r30 = 6;
        r31 = -10;
        break;
    case 4:
        r30 = 6;
        r31 = -20;
        break;
    }
    obj = lbl_805A0F88;
    switch (obj->unk24) {
    case 1:
        r31 = r31 + 0xFFFF11B8;
        fn_80338938(r30, r31);
        break;
    case 2:
        r31 = r31 + 0xFFFF11B8;
        if (lbl_805A0F88->unk9c < 1) {
            fn_80338938(r30, r31);
        } else {
            fn_80335638(2, lbl_8048A398);
        }
        break;
    case 5:
        r31 = r31 - 0x10000;
        r31 = r31 - 0x3C68;
        fn_80341220(r30, r31);
        break;
    case 4:
        r31 = r31 - 0x10000;
        r31 = r31 - 0x1558;
        break;
    default:
        r31 = r31 - 0x10000;
        r31 = r31 - 0x6378;
        break;
    }
    fn_80336F14(r30, r31);
    return arg0;
}
