#include <types.h>
#include <stdio.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef struct Profile {
    char pad[0x1c];
    int id;
} Profile;
typedef struct State {
    void *handle;
    int state;
    char pad08[12];
    void (*callback)(int, int, void *);
    void *context;
    Profile *profile;
    char pad20[16];
    int active;
} State;
typedef struct Timing {
    char pad[0x4b8];
    s64 start;
    s64 elapsed;
} Timing;
typedef struct Result {
    int error;
    int id;
} Result;

extern State *lbl_805A0F80;
extern char lbl_80489A00[];
extern void fn_80335638(int, const char *, ...);
extern void fn_8033524C(int, int);
extern int fn_8034F7A4(void);
extern u64 fn_8034F684(void);
extern int *fn_8034F79C(void);
extern void fn_80368058(void *, int, const char *);
extern int fn_803389F0();
extern Timing *fn_8034E158(void);
extern s64 fn_803F1470(s64, s64);
extern int fn_80342554(void);
extern void fn_80342328(int);
extern int fn_8033AAF0(void);
extern int fn_8033CD90(int);
extern void fn_803391A8(void);
extern void fn_80367F78(void *, int, int, int, void (*)(void), int);

void fn_80338B04(void *arg0, Result *arg1) {
    const char *base = lbl_80489A00;
    char buf[32];
    u64 user;
    int value;
    s64 elapsed;

    fn_80335638(0x20, base + 0xec, arg1->error);
    lbl_805A0F80->active = 0;
    value = fn_8034F7A4();
    user = fn_8034F684();
    snprintf(buf, 0x1f, base + 0x11c, fn_8034F79C(), user, value);
    fn_80368058(arg0, 0x704, buf);
    if (fn_803389F0() == 0) {
        if (arg1->error == 0) {
            int state = lbl_805A0F80->state;
            if (state == 2) {
                if (lbl_805A0F80->profile->id == arg1->id) {
                    fn_80335638(0x20, base + 0x12c);
                    lbl_805A0F80->state = 5;
                    elapsed = OSGetTime();
                    elapsed -= fn_8034E158()->start;
                    fn_8034E158()->elapsed = elapsed;
                    fn_80335638(0x200000, base + 0x148, (int)fn_803F1470(fn_8034E158()->elapsed, (u32)(OS_TIME_SPEED / 1000)));
                    fn_80335638(0x200000, base + 0x164, fn_80342554());
                    fn_80342328(1);
                    if (fn_803389F0() == 0) {
                        lbl_805A0F80->callback(0, arg1->id, lbl_805A0F80->context);
                        if (fn_8033AAF0() == 0) {
                            switch (fn_8033CD90(arg1->id)) {
                            case 0:
                                return;
                            default:
                                break;
                            }
                        }
                    }
                } else {
                    fn_80335638(0x20, base + 0x184);
                    if (lbl_805A0F80 != 0) {
                        fn_8033524C(6, -60000);
                        if (lbl_805A0F80->callback != 0)
                            lbl_805A0F80->callback(6, 0, lbl_805A0F80->context);
                        if (lbl_805A0F80 != 0) {
                            lbl_805A0F80->state = 0;
                            lbl_805A0F80->active = 0;
                            return;
                        }
                    }
                }
            } else {
                if (state == 3) {
                    fn_80367F78(arg0, arg1->id, 0, 0, fn_803391A8, 0);
                    if (fn_803389F0() != 0) {
                        return;
                    }
                }
            }
        } else {
            fn_803389F0(arg1->error);
        }
    }
}
