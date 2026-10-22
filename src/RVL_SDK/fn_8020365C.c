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
int fn_80203B90(Obj *);
extern void *(*lbl_8059EB20)(int);
extern void (*lbl_8059EB24)(void *);

static void freeAll(Obj *p) {
    int en = OSDisableInterrupts();
    unsigned int i;
    p->flags |= 1;
    for (i = 0; i < 3; i++) {
        if (p->buf[i] != 0) {
            lbl_8059EB24(p->buf[i]);
            p->buf[i] = 0;
        }
    }
    OSRestoreInterrupts(en);
}

static int allocAll(Obj *p) {
    unsigned int i;
    for (i = 0; i < 3; i++) {
        p->buf[i] = lbl_8059EB20(p->size[i] * 4);
        if (p->buf[i] == 0) return 0;
    }
    return 1;
}

int fn_8020365C(Obj *p) {
    int en = OSDisableInterrupts();
    int i;
    p->flags = 1;
    for (i = 0; i < 3; i++) {
        if (p->count[i] == 0) {
            freeAll(p);
            OSRestoreInterrupts(en);
            return 0;
        }
        p->size[i] = p->count[i] << 5;
    }
    if (!allocAll(p)) {
        freeAll(p);
        OSRestoreInterrupts(en);
        return 0;
    }
    if (fn_80203B90(p) == 0) {
        freeAll(p);
        OSRestoreInterrupts(en);
        return 0;
    }
    p->flags = (p->flags | 2) & ~1;
    OSRestoreInterrupts(en);
    return 1;
}
