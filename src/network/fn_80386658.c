#pragma force_active on
extern int closesocket(int);
extern int fn_8035A590(int);
extern int *fn_8035A598(int, int);
extern int lbl_805A10F0;

void fn_80386658(int arg0) {
    int v;
    int *t;

    if (lbl_805A10F0 == 0) {
        v = 0;
    } else {
        v = 0;
        while (v < fn_8035A590(lbl_805A10F0)) {
            t = fn_8035A598(lbl_805A10F0, v);
            if (t[2] == arg0) {
                v = (int)t;
                goto found;
            }
            v++;
        }
        v = 0;
    }
found:
    if (v != 0) {
        if (((int *)v)[0] != -1) {
            closesocket(((int *)v)[0]);
        }
        ((int *)v)[0] = -1;
        ((int *)v)[4] = 4;
    }
}
