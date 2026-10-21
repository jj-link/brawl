#pragma force_active on
typedef struct Entry {
    unsigned char active;
    unsigned char pad1[3];
    int type;
    unsigned char pad2[0x50];
    short value;
    unsigned char pad3[2];
} Entry;

extern const unsigned char lbl_805A3AA0[8];
extern unsigned char lbl_8052CDC0[0x7E8];

extern int fn_803F6150(const void *, const void *, unsigned long);
extern Entry *fn_8024E73C(const void *);

int fn_8024ADB0(const void *arg0, short arg1)
{
    Entry *p;

    if (fn_803F6150(lbl_805A3AA0, arg0, 6) != 0) {
        p = fn_8024E73C(arg0);
        if (p != 0 && p->active != 0 && p->type == 4) {
            p->value = arg1;
        } else {
            return 0;
        }
    } else {
        int i;

        p = (Entry *)(lbl_8052CDC0 + 8);
        for (i = 0; i < 4; ++i, ++p) {
            if (p->active != 0 && p->type == 4) {
                p->value = arg1;
            }
        }
    }

    return 1;
}
