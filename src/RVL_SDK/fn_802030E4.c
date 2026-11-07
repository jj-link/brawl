#include <string.h>
#pragma force_active on

typedef struct {
    void *a[3];
    char pad0[0x10];
    unsigned int a_count;
    char pad1[0xc];
    void *b[3];
    char pad2[8];
    unsigned int b_count;
    void *c[3][3];
    char pad3[0x18];
    unsigned int c_count[3];
    char pad4[0xc];
    void *d[3][2];
    char pad5[0x10];
    unsigned int d_count[2];
    void *e[3];
    char pad6[0x18];
    unsigned int e_count[3];
} Data;

void fn_802030E4(Data *p) {
    unsigned int i, j;
    for (i = 0; i < 3; i++) {
        if (p->a[i]) {
            memset(p->a[i], 0, p->a_count * 4);
        }
        if (p->b[i]) {
            memset(p->b[i], 0, p->b_count * 4);
        }
        for (j = 0; j < 3; j++) {
            if (p->c[i][j]) {
                memset(p->c[i][j], 0, p->c_count[j] * 4);
            }
        }
        for (j = 0; j < 2; j++) {
            if (p->d[i][j]) {
                memset(p->d[i][j], 0, p->d_count[j] * 4);
            }
        }
        if (p->e[i]) {
            memset(p->e[i], 0, p->e_count[i] * 4);
        }
    }
}