#pragma force_active on
extern void *(*lbl_8059EB20)(int);

typedef struct {
    void *a[3];
    char p0[0x10];
    int n1C;
    char p1[0xC];
    void *b[3];
    char p2[0x8];
    int n40;
    void *c[3][3];
    char p3[0x18];
    int s80[3];
    char p4[0xC];
    void *d[3][2];
    char p5[0x10];
    int s0C0[2];
    void *e[3];
    char p6[0x18];
    int s0EC[3];
} Obj;

int fn_80202F70(Obj *arg0) {
    unsigned int i, j;
    void *tmp;

    for (i = 0; i < 3; i++) {
        tmp = lbl_8059EB20(arg0->n1C * 4);
        arg0->a[i] = tmp;
        if (tmp == 0) {
            return 0;
        }
        if (arg0->n40 != 0) {
            tmp = lbl_8059EB20(arg0->n40 * 4);
            arg0->b[i] = tmp;
            if (tmp == 0) {
                return 0;
            }
        } else {
            arg0->b[i] = 0;
        }
        for (j = 0; j < 3; j++) {
            tmp = lbl_8059EB20(arg0->s80[j] * 4);
            arg0->c[i][j] = tmp;
            if (tmp == 0) {
                return 0;
            }
        }
        for (j = 0; j < 2; j++) {
            tmp = lbl_8059EB20(arg0->s0C0[j] * 4);
            arg0->d[i][j] = tmp;
            if (tmp == 0) {
                return 0;
            }
        }
        tmp = lbl_8059EB20(arg0->s0EC[i] * 4);
        arg0->e[i] = tmp;
        if (tmp == 0) {
            return 0;
        }
    }
    return 1;
}
