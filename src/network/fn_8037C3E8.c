#pragma force_active on

typedef struct Buffer {
    int owner;
    char *data;
    int capacity;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
} Buffer;

typedef struct NetSlot {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    short unk20;
    char gap22[2];
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    Buffer buf54;
    Buffer buf78;
    Buffer buf9C;
    Buffer bufC0;
    Buffer bufE4;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    char gap138[0x18];
    int unk150;
    char gap154[4];
    int unk158;
    int unk15C;
    int unk160;
    char gap164[0x20];
    int unk184;
    int unk188;
    short unk18C;
    char gap18E[2];
    int unk190;
    char gap194[0x1C];
    int unk1B0;
} NetSlot;

extern void fn_8037BE74(void);
extern void fn_8037BE78(void);
extern int fn_8037C2DC(void);
extern void fn_8037C5AC(void *);
extern int fn_8037B3FC(void *owner, void *buffer, int size, int limit);
extern void *memset(void *, int, unsigned long);
extern void **lbl_805A1074;
extern int lbl_805A1068;
extern int lbl_805A106C;

void *fn_8037C3E8(void) {
    NetSlot *slot;
    int idx;
    int serial;
    int r;
    int count;

    fn_8037BE74();
    idx = fn_8037C2DC();
    if (idx == -1) {
        fn_8037BE78();
        return 0;
    }
    slot = (NetSlot *)lbl_805A1074[idx];
    memset(slot, 0, 0x1B4);
    slot->unk0 = 1;
    slot->unk4 = idx;
    serial = lbl_805A1068;
    slot->unk8 = serial;
    lbl_805A1068 = serial + 1;
    slot->unkC = 0;
    slot->unk10 = 0;
    slot->unk14 = 0;
    slot->unk18 = 0;
    slot->unk1C = 0;
    slot->unk20 = 0;
    slot->unk24 = 0;
    slot->unk2C = 0;
    slot->unk30 = 0;
    slot->unk34 = 0;
    slot->unk38 = 0;
    slot->unk3C = 0;
    slot->unk40 = 0;
    slot->unk44 = 0;
    slot->unk48 = 0;
    slot->unk4C = -1;
    slot->unk50 = 0;
    slot->unk108 = 0;
    slot->unk10C = 0;
    slot->unk110 = 0;
    slot->unk114 = 0;
    slot->unk118 = 0;
    slot->unk11C = 0;
    slot->unk120 = 0;
    slot->unk124 = 0;
    slot->unk128 = -1;
    slot->unk12C = 0;
    slot->unk130 = 0;
    slot->unk134 = 0;
    slot->unk150 = 0;
    slot->unk158 = 0;
    slot->unk15C = 0;
    slot->unk160 = 0;
    slot->unk184 = 0x1F4;
    slot->unk18C = 0x50;
    slot->unk188 = 0;
    slot->unk190 = 0;
    slot->unk1B0 = 0;

    r = fn_8037B3FC(slot, &slot->buf54, 0x800, 0x1000);
    if (r != 0) {
        r = fn_8037B3FC(slot, &slot->buf78, 0x800, 0x400);
    }
    if (r != 0) {
        r = fn_8037B3FC(slot, &slot->buf9C, 0x800, 0x800);
    }
    if (r != 0) {
        r = fn_8037B3FC(slot, &slot->bufC0, 0x800, 0x400);
    }
    if (r == 0) {
        fn_8037C5AC(slot);
        fn_8037BE78();
        return 0;
    }
    count = lbl_805A106C;
    lbl_805A106C = count + 1;
    fn_8037BE78();
    return slot;
}
