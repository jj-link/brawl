#include <types.h>
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
} State;
extern State *lbl_805A0F80;
extern const char lbl_80489AB8[];
extern void fn_80335638(int, const char *, ...);
extern void fn_8033524C(int, int);
extern int fn_80335238(void);
extern void fn_80338F5C(void);
extern void fn_80367C74(void *);
extern s64 fn_803F1470(s64, s64);
void fn_803387A0(void)
{
    State *p;
    s64 t;
    void *handle;
    if (lbl_805A0F80 == 0 || fn_80335238() != 0) {
        return;
    } else {
        switch (lbl_805A0F80->state) {
        case 1:
            fn_80338F5C();
            break;
        case 2:
        case 3:
        case 4:
            handle = lbl_805A0F80->handle;
            if (handle != 0 && *(int *)handle != 0)
                fn_80367C74(handle);
            if (lbl_805A0F80->active != 0) {
                t = OSGetTime();
                p = lbl_805A0F80;
                if (fn_803F1470(t - p->time, OS_TIME_SPEED / 1000) > 0xEA60) {
                    if (p != 0) {
                        fn_8033524C(6, 0xFFFF1172);
                        if (lbl_805A0F80->callback != 0)
                            lbl_805A0F80->callback(6, 0, lbl_805A0F80->context);
                        if (lbl_805A0F80 != 0) {
                            lbl_805A0F80->state = 0;
                            lbl_805A0F80->active = 0;
                        }
                    }
                    lbl_805A0F80->active = 0;
                }
            }
            break;
        case 0:
        case 5:
        default:
            fn_80335638(4, lbl_80489AB8);
            break;
        }
    }
}
