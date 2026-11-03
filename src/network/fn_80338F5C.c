#include <revolution/OS/OSTime.h>
#pragma force_active on
typedef struct State {
    void *handle;
    int state;
    char pad08[12];
    void (*callback)(int, int, void *);
    void *context;
    void *field1c;
    char pad20[16];
    int active;
    char pad34[4];
    s64 time;
    unsigned int field40[3];
    char field4c[256];
    char field14c[256];
} State;
extern State *lbl_805A0F80;
extern char lbl_80489A00[];
extern void fn_80352418(void);
extern int fn_80352AB8(void);
extern int fn_80352AF4(void);
extern int fn_80352B0C(void);
extern void fn_80352B18(char *, char *);
extern long long fn_80352B64(void);
extern int fn_80351284(void *);
extern void fn_80350C24(void *, long long);
extern void fn_80335638(int, const char *, ...);
extern void fn_8033524C(int, int);
extern int fn_803389F0(void);
extern void fn_80338B04(void);
extern void fn_80367D20(void *, void *, void *, int, int, void (*)(void), int);

void fn_80338F5C(void) {
    const char *base = lbl_80489A00;
    int error;
    s64 time;
    fn_80352418();
    if (fn_80352AB8() != 0) {
        if (fn_80352AF4() != 0) {
            fn_80335638(0x20, base + 0x2f0);
            fn_80352B18(lbl_805A0F80->field4c, lbl_805A0F80->field14c);
            if (fn_80351284(lbl_805A0F80->field1c) != 0) {
                fn_80335638(0x20, base + 0x300);
                time = OSGetTime();
                lbl_805A0F80->time = time;
                lbl_805A0F80->active = 1;
                fn_80367D20(lbl_805A0F80->handle, lbl_805A0F80->field4c, lbl_805A0F80->field14c, 1, 0, fn_80338B04, 0);
                if (fn_803389F0() == 0) {
                    lbl_805A0F80->state = 2;
                }
            } else {
                fn_80350C24(lbl_805A0F80->field40, fn_80352B64());
                fn_80335638(0x20, base + 0x300);
                time = OSGetTime();
                lbl_805A0F80->time = time;
                lbl_805A0F80->active = 1;
                fn_80367D20(lbl_805A0F80->handle, lbl_805A0F80->field4c, lbl_805A0F80->field14c, 1, 0, fn_80338B04, 0);
                if (fn_803389F0() == 0) {
                    lbl_805A0F80->state = 3;
                }
            }
        } else {
            error = fn_80352B0C();
            fn_80335638(0x20, base + 0x328, error);
            if (error <= -0x7148) {
                if (lbl_805A0F80 != 0) {
                    fn_8033524C(9, error);
                    if (lbl_805A0F80->callback != 0)
                        lbl_805A0F80->callback(9, 0, lbl_805A0F80->context);
                    if (lbl_805A0F80 != 0) {
                        lbl_805A0F80->state = 0;
                        lbl_805A0F80->active = 0;
                    }
                }
            } else if (lbl_805A0F80 != 0) {
                fn_8033524C(2, error);
                if (lbl_805A0F80->callback != 0)
                    lbl_805A0F80->callback(2, 0, lbl_805A0F80->context);
                if (lbl_805A0F80 != 0) {
                    lbl_805A0F80->state = 0;
                    lbl_805A0F80->active = 0;
                }
            }
        }
    }
}