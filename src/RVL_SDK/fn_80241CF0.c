#pragma force_active on
extern void *fn_8023A038(void *);
extern short *fn_8023C7FC(void *);

void fn_80241CF0(void *a, int b) {
    unsigned char *p;
    short *q;

    p = fn_8023A038(a);
    if (p != 0) {
        b = b | 0x8000;
        *(short *)(p + 0x1a) = b;
        q = fn_8023C7FC(p + 0x1c);
        if (q != 0) {
            *q = b;
        }
    }
}
