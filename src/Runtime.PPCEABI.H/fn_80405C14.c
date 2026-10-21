#pragma force_active on
typedef unsigned char u8;

typedef struct DBCommTable {
    int unk0;
    void (*unk4)(struct DBCommTable*);
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
} DBCommTable;

extern u8 TRK_Use_BBA;
extern DBCommTable gDBCommTable;

void fn_80405C14(void) {
    if (TRK_Use_BBA == 0 && gDBCommTable.unk4 != 0) {
        gDBCommTable.unk4(&gDBCommTable);
    }
}
