#pragma force_active on
extern unsigned char lbl_8052CDC0[];

typedef struct {
    unsigned char active;
    unsigned char pad1[0x27];
    unsigned short value;
    unsigned char pad2[0x32];
} Entry;

void *fn_8024E7C4(unsigned short arg0) {
    Entry *p = (Entry *)(lbl_8052CDC0 + 8);
    int i;
    for (i = 0; i < 4; i++) {
        if (p->active && p->value == arg0)
            return p;
        p++;
    }
    return 0;
}
