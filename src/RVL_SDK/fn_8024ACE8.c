#pragma force_active on
typedef struct Entry {
    unsigned char active;
    unsigned char pad1[3];
    int type;
    unsigned char pad2[0x50];
    short value;
} Entry;
typedef struct Channel {
    unsigned char pad[0x10];
    Entry *entry;
} Channel;
extern unsigned char lbl_8052CDC0[];
extern char lbl_80482E48[];
extern void fn_802319FC(int, void *, int);
extern Channel *fn_8024FC18(int, int);

int fn_8024ACE8(int arg0, short arg1, int arg2)
{
    Channel *p;
    Entry *entry;
    if (arg2 != 0) {
        *(short *)(lbl_8052CDC0 + 0x7ba) = arg1;
    } else {
        p = fn_8024FC18(0, arg0);
        if (p == 0) {
            if (lbl_8052CDC0[0] >= 2) {
                fn_802319FC(0x80001, lbl_80482E48, arg0);
            }
            return 0;
        }
        entry = p->entry;
        if (entry != 0 && entry->active != 0 && entry->type == 4) {
            entry->value = arg1;
        } else {
            return 0;
        }
    }
    return 1;
}