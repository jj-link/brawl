#pragma force_active on
typedef struct DBCommTable {
    int unk0;
    int unk4;
    int unk8;
    void (*unkC)(struct DBCommTable*);
} DBCommTable;

extern DBCommTable gDBCommTable;

void fn_80405BE4(void) {
    gDBCommTable.unkC(&gDBCommTable);
}
