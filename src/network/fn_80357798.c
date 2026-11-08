#pragma force_active on
typedef struct Obj {
    int type;
    char pad[8];
    void *p0c;
    char pad10[4];
    void *p14;
    void *p18;
    void *p1c;
} Obj;
extern void (*lbl_805A1024)(void *);
void fn_80357798(Obj *p) {
    if (p) {
        switch (p->type) {
        case 1:
            break;
        case 2:
            if (p->p1c) {
                lbl_805A1024(p->p1c);
                p->p1c = 0;
            }
            if (p->p18) {
                lbl_805A1024(p->p18);
                p->p18 = 0;
            }
            lbl_805A1024(p->p14);
            p->p14 = 0;
            break;
        case 3:
            lbl_805A1024(p->p0c);
            p->p0c = 0;
            break;
        }
        lbl_805A1024(p);
    }
}