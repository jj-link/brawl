#pragma force_active on
typedef struct DBCommTable {
    unsigned char unk00[0x20];
    void (*unk20)(struct DBCommTable*);
} DBCommTable;

extern DBCommTable gDBCommTable;

void UnreserveEXI2Port(void) {
    gDBCommTable.unk20(&gDBCommTable);
}
