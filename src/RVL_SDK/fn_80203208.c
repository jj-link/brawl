#pragma force_active on
extern void (*lbl_8059EB24)(void *);

typedef struct {
    void *a[3];
    char pad0[0x20];
    void *b[3];
    char pad1[0xc];
    void *c[3][3];
    char pad2[0x30];
    void *d[3][2];
    char pad3[0x18];
    void *e[3];
} Data;

void fn_80203208(Data *p) {
    unsigned int i, j;
    for (i = 0; i < 3; i++) {
        if (p->a[i]) {
            lbl_8059EB24(p->a[i]);
            p->a[i] = 0;
        }
        if (p->b[i]) {
            lbl_8059EB24(p->b[i]);
            p->b[i] = 0;
        }
        for (j = 0; j < 3; j++) {
            if (p->c[i][j]) {
                lbl_8059EB24(p->c[i][j]);
                p->c[i][j] = 0;
            }
        }
        for (j = 0; j < 2; j++) {
            if (p->d[i][j]) {
                lbl_8059EB24(p->d[i][j]);
                p->d[i][j] = 0;
            }
        }
        if (p->e[i]) {
            lbl_8059EB24(p->e[i]);
            p->e[i] = 0;
        }
    }
}