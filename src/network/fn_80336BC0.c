#include <revolution/OS/OSTime.h>

#pragma force_active on

typedef struct State {
    int state;
    int *handle;
    unsigned int count;
    int pad;
    s64 time;
    int index;
    void *object;
    unsigned char current;
    unsigned char arg;
    unsigned char mode;
    unsigned char done;
    int flag;
    char pad28[8];
    void (*callback)(int, int, void *);
    void *context;
} State;

extern State *lbl_805A0F70;
extern int lbl_805A0F78;
extern int lbl_805A0F7C;
extern char lbl_804894BC[];

extern int fn_80335238(void);
extern s64 fn_803F1470(s64, s64);
extern int fn_80367C74(int *);
extern int fn_80383698(void);
extern int fn_803836B0(void);
extern void fn_80383470(void);
extern void fn_80335638(int, const char *, ...);
extern void fn_80337474(void *, int);

void fn_80336BC0(void)
{
    s64 now;
    State *p31;
    void *v30;

    if (lbl_805A0F70 == 0 || fn_80335238() != 0) {
        return;
    } else {
        if (lbl_805A0F70->object == 0) {
            if (lbl_805A0F70->handle != 0 && *lbl_805A0F70->handle != 0) {
                now = OSGetTime();
                v30 = lbl_805A0F70;
                if (fn_803F1470(now - ((State *)v30)->time, OS_TIME_SPEED / 1000) >= 300) {
                    ((State *)v30)->count++;
                    fn_80367C74(lbl_805A0F70->handle);
                    lbl_805A0F70->time = OSGetTime();
                }
            }
            return;
        }

        if (lbl_805A0F70->flag != 0 || fn_80383698() != 0) {
            lbl_805A0F78 = 1;
            lbl_805A0F7C = 0;
            if (fn_803836B0() == 0) {
                lbl_805A0F78 = 0;
                fn_80335638(8, lbl_804894BC);
            }
            lbl_805A0F78 = 0;
            if (lbl_805A0F7C == 1) {
                lbl_805A0F7C = 0;
                fn_80383470();
            }
        }

        if (lbl_805A0F70->handle != 0 && *lbl_805A0F70->handle != 0) {
            v30 = 0;
            now = OSGetTime();
            p31 = lbl_805A0F70;
            if (fn_803F1470(now - p31->time, OS_TIME_SPEED / 1000) >= 300) {
                p31->count++;
                v30 = (void *)(long)fn_80367C74(lbl_805A0F70->handle);
                now = OSGetTime();
                p31 = lbl_805A0F70;
                p31->time = now;
            }
            if (v30 != 0)
                return;
            if (p31->state == 0)
                return;
            if (p31->object != 0 && p31->mode != 3 && p31->count > 7) {
                if (p31->mode <= 1)
                    fn_80337474(p31->object, p31->index);
                if (lbl_805A0F70->current >= lbl_805A0F70->index) {
                    lbl_805A0F70->mode = 3;
                    lbl_805A0F70->done++;
                }
            }
        }

        if (lbl_805A0F70->done >= 2) {
            lbl_805A0F70->done = 0;
            lbl_805A0F70->callback(0, lbl_805A0F70->arg, lbl_805A0F70->context);
            lbl_805A0F70->state = 2;
        }
    }
}
