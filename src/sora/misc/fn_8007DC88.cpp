#pragma force_active on
extern "C" {
struct BigStruct {
    char pad0[0x808];
    unsigned long long entries[5];
    char pad1[4];
    int index;
    char pad2[0x10];
    unsigned long long total;
};
extern struct BigStruct *lbl_805A01F8;
unsigned int fn_8007D9F8(short *, short *, unsigned int, int *);
void *memset(void *, int, unsigned long);
void fn_8007DC88(short *arg0, short *arg1, unsigned int arg2) {
    int sp8;
    unsigned int n;
    unsigned int size;
    unsigned long long acc;
    unsigned int remaining = arg2;
    short *p0;
    short *p1;
    acc = lbl_805A01F8->total;
    p0 = arg0;
    p1 = arg1;
    for (;;) {
        n = fn_8007D9F8(p0, p1, remaining, &sp8);
        acc += n;
        if (sp8 == 0) {
            break;
        }
        if (sp8 == 1) {
            remaining -= n;
            p0 += n;
            if (p1 != 0) {
                p1 += n;
            }
            lbl_805A01F8->entries[lbl_805A01F8->index] = acc;
            lbl_805A01F8->index++;
            if (lbl_805A01F8->index >= 5) {
                lbl_805A01F8->index = 0;
            }
            continue;
        }
        size = remaining * 2;
        memset(p0, 0, size);
        if (p1 != 0) {
            memset(p1, 0, size);
        }
        break;
    }
    lbl_805A01F8->total += arg2;
}
}