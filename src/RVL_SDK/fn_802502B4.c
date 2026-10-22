#pragma force_active on
typedef struct Entry {
    unsigned char flag;
    unsigned char pad[3];
    int id;
    unsigned char rest[0x54];
} Entry;

extern unsigned char lbl_8052CDC0[0x7E8];

void *fn_802502B4(int arg0) {
    Entry *e = (Entry *)(lbl_8052CDC0 + 8);

    if (e->flag != 0 && e->id == arg0) {
        return e;
    }
    e = (Entry *)((unsigned char *)e + 0x5C);
    if (e->flag != 0 && e->id == arg0) {
        return e;
    }
    e = (Entry *)((unsigned char *)e + 0x5C);
    if (e->flag != 0 && e->id == arg0) {
        return e;
    }
    e = (Entry *)((unsigned char *)e + 0x5C);
    if (e->flag != 0 && e->id == arg0) {
        return e;
    }
    return 0;
}
