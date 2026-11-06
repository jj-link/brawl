#pragma force_active on
typedef struct {
    void *buf[3];
    int pad[3];
    int size[3];
    int pad2[6];
    int flags;
    int count[3];
} Obj;

int OSDisableInterrupts(void);
void OSRestoreInterrupts(int);
int fn_8020365C(Obj *p);
extern void (*lbl_8059EB24)(void *);

int fn_8020385C(Obj *p) {
    int en3;
    unsigned int i;
    int en2;
    unsigned int j;
    void **q;
    int en1 = OSDisableInterrupts();
    p->flags |= 1;
    en2 = OSDisableInterrupts();
    p->flags |= 1;
    q = (void **)p;
    for (i = 0; i < 3; i++) {
        if (*q != 0) {
            lbl_8059EB24(*q);
            *q = 0;
        }
        q++;
    }
    OSRestoreInterrupts(en2);
    if (fn_8020365C(p) == 0) {
        en3 = OSDisableInterrupts();
        p->flags |= 1;
        q = (void **)p;
        for (j = 0; j < 3; j++) {
            if (*q != 0) {
                lbl_8059EB24(*q);
                *q = 0;
            }
            q++;
        }
        OSRestoreInterrupts(en3);
        OSRestoreInterrupts(en1);
        return 0;
    }
    p->flags = (p->flags | 2) & ~1;
    OSRestoreInterrupts(en1);
    return 1;
}
