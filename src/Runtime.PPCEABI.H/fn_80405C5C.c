#pragma force_active on
typedef struct DBCommTable {
    void (*unk0)(int, void*);
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    void (*unk18)(struct DBCommTable*);
    int unk1C;
    int unk20;
    int unk24;
} DBCommTable;

extern DBCommTable gDBCommTable;
extern void TRKEXICallBack(int arg1, void* arg2);

int TRKInitializeIntDrivenUART(int a, int b, int c, int d) {
    gDBCommTable.unk0(d, (void*)TRKEXICallBack);
    gDBCommTable.unk18(&gDBCommTable);
    return 0;
}
