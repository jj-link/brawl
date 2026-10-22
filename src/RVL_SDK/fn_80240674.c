#pragma force_active on
extern char lbl_80529CF8[];
extern void *fn_8023A0F0(void);

void fn_80240674(int arg0) {
    char *p = fn_8023A0F0();
    if (p != 0) {
        void (*f)(int, char *, char *) = *(void (**)(int, char *, char *))(lbl_80529CF8 + 0x1920);
        if (f != 0) {
            f(arg0, p + 0x22, p + 0x35);
        }
        {
            unsigned char t = *(unsigned char *)(p + 0x7F);
            if (t == 4 || t == 1) {
                *(unsigned char *)(p + 0x7F) = 0;
                if (*(unsigned char *)(p + 0x80) != 0) {
                    int *q = *(int **)p;
                    if (q != 0 && (unsigned)q[0] == 3) {
                        q[1] = 0;
                    }
                }
                *(int *)(p + 4) = 0;
            }
        }
    }
}
