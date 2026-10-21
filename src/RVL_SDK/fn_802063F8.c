#pragma force_active on
typedef unsigned int u32;

typedef struct HalfField {
    short value;
    short pad;
} HalfField;

typedef struct Entry {
    int unk0;
    u32 unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    char pad24[0x18];
    HalfField fields[13];
} Entry;

extern int fn_801FF1F4(void);
extern u32 fn_802025CC(void);
extern void fn_80206308(Entry *);
extern void fn_802097C4(u32);

extern Entry lbl_804E8A80[];
extern char lbl_804EB480[];
extern Entry *lbl_805A0B60;
extern int lbl_805A0B64;
extern u32 lbl_805A0B68;
extern int lbl_805A0B6C;
extern void *lbl_805A0B70;

void fn_802063F8(void)
{
    u32 i;
    Entry *p;

    if (fn_801FF1F4()) {
        lbl_805A0B68 = fn_802025CC();
        lbl_805A0B60 = lbl_804E8A80;
        lbl_805A0B70 = lbl_804EB480;

        for (i = 0; i < lbl_805A0B68; i++) {
            lbl_805A0B60[i].unk0 = 0;
            p = &lbl_805A0B60[i];
            p->unk4 = 0x50000000;
            p->unk8 = 0;
            p->unkC = -0x3C0;
            p->unk10 = -0x3C0;
            p->unk14 = -0x3C0;
            p->unk20 = 0;
            p->unk18 = 0x40;
            p->unk1C = 0x7F;
            p->fields[0].value = p->fields[1].value =
            p->fields[2].value = p->fields[3].value =
            p->fields[4].value = p->fields[5].value =
            p->fields[6].value = p->fields[7].value =
            p->fields[8].value = p->fields[9].value =
            p->fields[10].value = p->fields[11].value =
            p->fields[12].value = 0;

            fn_80206308(p);
            fn_802097C4(i);
        }

        lbl_805A0B6C = 1;
        lbl_805A0B64 = 1;
    }
}
