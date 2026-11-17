#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef struct State {
    void *handle;
    int state;
    char pad08[4];
    int unkC;
    char pad10[12];
    void *field1c;
    char pad20[16];
    int active;
    char pad34[4];
    s64 time;
    unsigned int field40[3];
    char field4c[256];
    char field14c[256];
} State;

typedef struct Msg {
    int error;
    int id;
    char pad08[0x86];
    char name[32];
} Msg;

extern State *lbl_805A0F80;
extern char lbl_80489A00[];
extern void fn_80335638(int, const char *, ...);
extern void fn_80350D74(void *, int, void *);
extern void fn_80351480(void *, void *, int);
extern void fn_80368058(void *, int, void *);
extern int fn_803389F0(void);
extern void fn_80338D90(void);
extern void fn_80367E4C(void *);
extern void fn_80367F78(void *, int, int, int, void (*)(void *, Msg *), int);
extern void fn_80367D20(void *, void *, void *, int, int, void (*)(void), int);
extern void fn_80338B04(void);
extern int strcmp(const char *, const char *);

void fn_803391A8(void *arg0, Msg *arg1) {
    int err;
    const char *base = lbl_80489A00;
    char sp38[24];
    char sp20[24];
    char sp8[24];
    s64 t;

    err = arg1->error;
    if (err == 0) {
        if (lbl_805A0F80->state == 3) {
            if (arg1->name[0] == 0) {
                fn_80335638(0x20, base + 0x340);
                fn_80350D74((char *)lbl_805A0F80->field1c + 4, lbl_805A0F80->unkC, sp38);
                fn_80368058(arg0, 0x705, sp38);
                if (fn_803389F0() == 0) {
                    lbl_805A0F80->state = 4;
                    fn_80367F78(arg0, arg1->id, 0, 0, fn_803391A8, 0);
                    if (fn_803389F0() == 0) {
                        fn_80335638(0x20, base + 0x374);
                    }
                }
            } else {
                fn_80335638(0x20, base + 0x38C);
                fn_80367E4C(arg0);
                fn_80338D90();
                lbl_805A0F80->state = 1;
            }
        } else if (lbl_805A0F80->state == 4) {
            fn_80350D74((char *)lbl_805A0F80->field1c + 4, lbl_805A0F80->unkC, sp20);
            if (strcmp(arg1->name, sp20) == 0) {
                fn_80350D74(&lbl_805A0F80->field40, lbl_805A0F80->unkC, sp8);
                fn_80335638(0x20, base + 0x3C0, sp8, sp20, arg1->id);
                fn_80351480(lbl_805A0F80->field1c, &lbl_805A0F80->field40, arg1->id);
                fn_80367E4C(arg0);
                fn_80335638(0x20, base + 0x300);
                t = OSGetTime();
                lbl_805A0F80->time = t;
                lbl_805A0F80->active = 1;
                fn_80367D20(lbl_805A0F80->handle, lbl_805A0F80->field4c, lbl_805A0F80->field14c, 1, 0, fn_80338B04, 0);
                if (fn_803389F0() == 0) {
                    lbl_805A0F80->state = 2;
                }
            } else {
                fn_80335638(0x20, base + 0x3E8, arg1->name, arg1->id);
                fn_80367F78(arg0, arg1->id, 0, 0, fn_803391A8, 0);
                if (fn_803389F0() != 0) {
                    return;
                }
            }
        }
    } else {
        fn_80335638(0x20, base + 0x428, err);
    }
}
