#include <types.h>
#pragma force_active on

extern "C" {
int fn_801C6B78(void *);
int fn_801C6BE4(void *, int, int *);
int fn_801C6C14(void *, int, int *);
int fn_801C96B8(void *, int);
void *fn_801BBD30(void *, int);
int fn_801C9804(void *, int);
void *fn_801BBD68(void *, int);
int fn_801BBDA8(void *, int);
}

struct Holder {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

struct Inner {
    int pad[4];
    void *unk10;
};

struct Outer {
    int unk0;
    struct Inner *unk4;
};

extern "C" int fn_801CA484(struct Outer *arg0, struct Outer *arg1, int arg2, int arg3) {
    int sp8;
    struct Holder sp10;
    int sp20[8];
    void *obj;
    int r;
    int v;

    if (arg0->unk4->unk10 == 0) {
        r = 0;
    } else {
        r = fn_801C6B78(arg0->unk4->unk10);
    }
    if (r == 0) {
        return 0;
    }
    obj = arg0->unk4->unk10;
    if (fn_801C6BE4(obj, (int)arg1->unk4, sp20) == 0) {
        return 0;
    }
    if (fn_801C6C14(obj, sp20[1], &sp8) == 0) {
        return 0;
    }
    r = fn_801C96B8(arg0->unk4, sp8);
    if (r == 0) {
        return 0;
    }
    fn_801BBD30(&sp10, r);
    v = fn_801C9804(arg0->unk4, sp8);
    if (v == 0) {
        fn_801BBD68(&sp10, -1);
        return 0;
    }
    sp10.unkC = v;
    r = fn_801BBDA8(&sp10, arg3);
    fn_801BBD68(&sp10, -1);
    return r;
}
