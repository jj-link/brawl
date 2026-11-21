#pragma force_active on
#pragma dollar_identifiers on

typedef void (*DBCommFn)(void);

typedef struct DBCommTable {
    DBCommFn unk0;
    DBCommFn unk4;
    DBCommFn unk8;
    DBCommFn unkC;
    DBCommFn unk10;
    DBCommFn unk14;
    DBCommFn unk18;
    DBCommFn unk1C;
    DBCommFn unk20;
    DBCommFn unk24;
} DBCommTable;

extern DBCommTable gDBCommTable;
extern unsigned char TRK_Use_BBA;
extern unsigned int EndofProgramInstruction$159_80420568[1];
extern void OSReport(const char* fmt, ...);

extern void udp_cc_initialize(void);
extern void udp_cc_open(void);
extern void udp_cc_close(void);
extern void udp_cc_read(void);
extern void udp_cc_write(void);
extern void udp_cc_shutdown(void);
extern void udp_cc_peek(void);
extern void udp_cc_pre_continue(void);
extern void udp_cc_post_stop(void);

extern void gdev_cc_initialize(void);
extern void gdev_cc_open(void);
extern void gdev_cc_close(void);
extern void gdev_cc_read(void);
extern void gdev_cc_write(void);
extern void gdev_cc_shutdown(void);
extern void gdev_cc_peek(void);
extern void gdev_cc_pre_continue(void);
extern void gdev_cc_post_stop(void);
extern void gdev_cc_initinterrupts(void);

static inline void init_udp(DBCommTable* tbl) {
    tbl->unk0 = udp_cc_initialize;
    tbl->unk18 = udp_cc_open;
    tbl->unk1C = udp_cc_close;
    tbl->unk10 = udp_cc_read;
    tbl->unk14 = udp_cc_write;
    tbl->unk8 = udp_cc_shutdown;
    tbl->unkC = udp_cc_peek;
    tbl->unk20 = udp_cc_pre_continue;
    tbl->unk24 = udp_cc_post_stop;
    tbl->unk4 = 0;
}

int InitMetroTRKCommTable(int arg) {
    char* base = (char*)EndofProgramInstruction$159_80420568;

    OSReport(base + 8, arg);
    OSReport(base + 0x20, 0x40);
    TRK_Use_BBA = 0;

    if (arg == 2) {
        OSReport(base + 0x48);
        TRK_Use_BBA = 1;
        init_udp(&gDBCommTable);
        return 0;
    }
    if (arg == 1) {
        OSReport(base + 0x60);
        gDBCommTable.unk0 = gdev_cc_initialize;
        gDBCommTable.unk18 = gdev_cc_open;
        gDBCommTable.unk1C = gdev_cc_close;
        gDBCommTable.unk10 = gdev_cc_read;
        gDBCommTable.unk14 = gdev_cc_write;
        gDBCommTable.unk8 = gdev_cc_shutdown;
        gDBCommTable.unkC = gdev_cc_peek;
        gDBCommTable.unk20 = gdev_cc_pre_continue;
        gDBCommTable.unk24 = gdev_cc_post_stop;
        gDBCommTable.unk4 = gdev_cc_initinterrupts;
        return 0;
    }
    OSReport(base + 0x84, arg);
    OSReport(base + 0xB0);
    OSReport(base + 0xE0);
    return 1;
}
