#pragma force_active on

typedef struct Entry {
    unsigned int a;
    unsigned int flags;
    unsigned char pad[0x68];
} Entry;

extern Entry *lbl_805A0B60;

void fn_80207BFC(int *arg0)
{
    Entry *p = lbl_805A0B60 + arg0[6];
    p->flags |= 0x40000001;
}
